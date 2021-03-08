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
  SIFIVE_EXT = 0,
  VENDOR_EXT_NUM
};

static htab_t op_sifive_hash;

static void
riscv_vendor_md_begin (void)
{
  /* Init vendor/unratified registers and opcode hash tables.  */
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
    case INSN_CLASS_XSFCACHE:
      return riscv_subset_supports ("xsfcache");
    default:
      as_fatal ("internal: unreachable");
      return FALSE;
    }
}

static bfd_boolean
validate_riscv_vendor_insn (insn_t *used_bits ATTRIBUTE_UNUSED,
			    const char **opcode_args)
{
  const char *oparg = *opcode_args;

#define USE_BITS(mask,shift) (*used_bits |= ((insn_t)(mask) << (shift)))
  switch (*oparg)
    {
    default:
      return FALSE;
    }

  *opcode_args = oparg;
  return TRUE;
}

static bfd_boolean
riscv_parse_vendor_operands (struct riscv_cl_insn *ip ATTRIBUTE_UNUSED,
			     expressionS *imm_expr ATTRIBUTE_UNUSED,
			     bfd_reloc_code_real_type *imm_reloc ATTRIBUTE_UNUSED,
			     const char **opcode_args,
			     char **assembly_args)
{
  const char *oparg = *opcode_args;
  char *asarg = *assembly_args;

  switch (*oparg)
    {
    default:
      return FALSE;
    }

  *opcode_args = oparg;
  *assembly_args = asarg;
  return TRUE;
}
