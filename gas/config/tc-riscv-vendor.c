/* tc-riscv-vendor.c -- Assemble vendor code for RISC-V
   Copyright (C) 2009-2021 Free Software Foundation, Inc.

   This file is part of GAS, the GNU Assembler.

   GAS is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   GAS is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with GAS; see the file COPYING.  If not, write to the Free
   Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA
   02110-1301, USA.  */

enum
{
  UNRATIFIED_EXT = 0,
  SIFIVE_EXT,
  VENDOR_EXT_NUM
};

static htab_t op_unratified_hash;
static htab_t op_sifive_hash;

static void
riscv_vendor_md_begin (void)
{
  /* Init vendor/unratified registers.  */
  hash_reg_names (RCLASS_VECR, riscv_vecr_names_numeric, NVECR);
  hash_reg_names (RCLASS_VECM, riscv_vecm_names_numeric, NVECM);

  /* Init vendor/unratified opcode hash tables.  */
  op_unratified_hash = init_opcode_hash (riscv_vendor_opcodes[UNRATIFIED_EXT], FALSE);
  op_sifive_hash = init_opcode_hash (riscv_vendor_opcodes[SIFIVE_EXT], FALSE);
}

static struct riscv_opcode *
riscv_find_vendor_opcode_hash (char *str)
{
  struct riscv_opcode *insn = NULL;
  unsigned int i;

  for (i = 0; i < VENDOR_EXT_NUM; i++)
    {
      if (insn != NULL)
	break;

      switch (i)
	{
	case UNRATIFIED_EXT:
	  insn = (struct riscv_opcode *) str_hash_find (op_unratified_hash, str);
	  continue;
	case SIFIVE_EXT:
	  insn = (struct riscv_opcode *) str_hash_find (op_sifive_hash, str);
	  continue;
	default:
	  break;
	}
    }

  return insn;
}

static bfd_boolean
riscv_vendor_subset_supports (int insn_class)
{
  switch (insn_class)
    {
    case INSN_CLASS_V:
      return riscv_subset_supports ("v");
    case INSN_CLASS_V_OR_ZVLSSEG:
      return riscv_subset_supports ("v") || riscv_subset_supports ("zvlsseg");

    case INSN_CLASS_XSFCACHE:
      return riscv_subset_supports ("xsfcache");

    default:
      as_fatal ("internal: unreachable");
      return FALSE;
    }
}

static bfd_boolean
validate_riscv_vendor_insn (insn_t *used_bits,
			    const char **opcode_args)
{
  const char *oparg = *opcode_args;

#define USE_BITS(mask,shift) (*used_bits |= ((insn_t)(mask) << (shift)))
  switch (*oparg)
    {
    case 'V': /* RVV */
      switch (*++oparg)
	{
	case 'd': USE_BITS (OP_MASK_VD, OP_SH_VD); break;
	case 's': USE_BITS (OP_MASK_VS1, OP_SH_VS1); break;
	case 't': USE_BITS (OP_MASK_VS2, OP_SH_VS2); break;
	case 'j': USE_BITS (OP_MASK_VIMM, OP_SH_VIMM); break;
	case 'm': USE_BITS (OP_MASK_VMASK, OP_SH_VMASK); break;
	case 'b': *used_bits |= ENCODE_RVV_VB_IMM (-1U); break;
	case 'c': *used_bits |= ENCODE_RVV_VC_IMM (-1U); break;
	default:
	  return FALSE;
	}
      break;
    default:
      return FALSE;
    }

  *opcode_args = oparg;
  return TRUE;
}

/* Parse string STR as a vsetvli operand.  Store the expression in *EP.
   On exit, EXPR_END points to the first character after the expression.  */

static void
my_getVsetvliExpression (expressionS *ep, char *str)
{
  unsigned int vsew_value = 0, vlmul_value = 0;
  unsigned int vta_value = 0, vma_value = 0;
  bfd_boolean vsew_found = FALSE, vlmul_found = FALSE;
  bfd_boolean vta_found = FALSE, vma_found = FALSE;

  if (arg_lookup (&str, riscv_vsew, ARRAY_SIZE (riscv_vsew), &vsew_value))
    {
      if (*str == ',')
	++str;
      if (vsew_found)
	as_bad (_("multiple vsew constants"));
      vsew_found = TRUE;
    }
  if (arg_lookup (&str, riscv_vlmul, ARRAY_SIZE (riscv_vlmul), &vlmul_value))
    {
      if (*str == ',')
	++str;
      if (vlmul_found)
	as_bad (_("multiple vlmul constants"));
      vlmul_found = TRUE;
    }
  if (arg_lookup (&str, riscv_vta, ARRAY_SIZE (riscv_vta), &vta_value))
    {
      if (*str == ',')
	++str;
      if (vta_found)
	as_bad (_("multiple vta constants"));
      vta_found = TRUE;
    }
  if (arg_lookup (&str, riscv_vma, ARRAY_SIZE (riscv_vma), &vma_value))
    {
      if (*str == ',')
	++str;
      if (vma_found)
	as_bad (_("multiple vma constants"));
      vma_found = TRUE;
    }

  if (vsew_found || vlmul_found || vta_found || vma_found)
    {
      ep->X_op = O_constant;
      ep->X_add_number = (vlmul_value << OP_SH_VLMUL)
			 | (vsew_value << OP_SH_VSEW)
			 | (vta_value << OP_SH_VTA)
			 | (vma_value << OP_SH_VMA);
      expr_end = str;
    }
  else
    {
      my_getExpression (ep, str);
      str = expr_end;
    }
}

static bfd_boolean
riscv_parse_vendor_operands (struct riscv_cl_insn *ip,
			     expressionS *imm_expr,
			     bfd_reloc_code_real_type *imm_reloc ATTRIBUTE_UNUSED,
			     const char **opcode_args,
			     char **assembly_args)
{
  const char *oparg = *opcode_args;
  char *asarg = *assembly_args;
  unsigned int regno;

  switch (*oparg)
    {
    case 'V': /* RVV */
      switch (*++oparg)
	{
	case 'd': /* VD */
	  if (!reg_lookup (&asarg, RCLASS_VECR, &regno))
	    return FALSE;
	  INSERT_OPERAND (VD, *ip, regno);
	  break;

	case 's': /* VS1 */
	  if (!reg_lookup (&asarg, RCLASS_VECR, &regno))
	    return FALSE;
	  INSERT_OPERAND (VS1, *ip, regno);
	  break;

	case 't': /* VS2 */
	  if (!reg_lookup (&asarg, RCLASS_VECR, &regno))
	    return FALSE;
	  INSERT_OPERAND (VS2, *ip, regno);
	  break;

	case 'j': /* vector arith unsigned immediate */
	  my_getExpression (imm_expr, asarg);
	  check_absolute_expr (ip, imm_expr, FALSE);
	  if (imm_expr->X_add_number < 0
	      || imm_expr->X_add_number >= 32)
	    {
	      as_bad (_("bad value for vector immediate field, "
			"value must be 0...31"));
	      return FALSE;
	    }
	  INSERT_OPERAND (VIMM, *ip, imm_expr->X_add_number);
	  imm_expr->X_op = O_absent;
	  asarg = expr_end;
	  break;

	case 'm': /* optional vector mask */
	  if (*asarg == '\0')
	    INSERT_OPERAND (VMASK, *ip, 1);
	  else if (*asarg == ',' && asarg++
		   && reg_lookup (&asarg, RCLASS_VECM, &regno)
		   && regno == 0)
	    INSERT_OPERAND (VMASK, *ip, 0);
	  break;

	case 'b': /* vtypei for vsetivli */
	  my_getVsetvliExpression (imm_expr, asarg);
	  check_absolute_expr (ip, imm_expr, FALSE);
	  if (!VALID_RVV_VB_IMM (imm_expr->X_add_number))
	    {
	      as_bad (_("bad value for vsetivli immediate field, "
			"value must be 0..1023"));
	      return FALSE;
	    }
	  ip->insn_opcode
	    |= ENCODE_RVV_VB_IMM (imm_expr->X_add_number);
	  imm_expr->X_op = O_absent;
	  asarg = expr_end;
	  break;

	case 'c': /* vtypei for vsetvli */
	  my_getVsetvliExpression (imm_expr, asarg);
	  check_absolute_expr (ip, imm_expr, FALSE);
	  if (!VALID_RVV_VC_IMM (imm_expr->X_add_number))
	    {
	      as_bad (_("bad value for vsetvli immediate field, "
			"value must be 0..2047"));
	      return FALSE;
	    }
	  ip->insn_opcode
	    |= ENCODE_RVV_VC_IMM (imm_expr->X_add_number);
	  imm_expr->X_op = O_absent;
	  asarg = expr_end;
	  break;
	}
      break;
    default:
      return FALSE;
    }

  *opcode_args = oparg;
  *assembly_args = asarg;
  return TRUE;
}
