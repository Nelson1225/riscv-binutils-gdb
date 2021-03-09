/* RISC-V vendor disassembler
   Copyright (C) 2011-2021 Free Software Foundation, Inc.

   Contributed by Andrew Waterman (andrew@sifive.com).
   Based on MIPS target.

   This file is part of the GNU opcodes library.

   This library is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   It is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; see the file COPYING3. If not,
   see <http://www.gnu.org/licenses/>.  */

static bfd_boolean
print_vendor_insn_args (const char **opcode_args,
			insn_t l,
			disassemble_info *info)
{
  fprintf_ftype print = info->fprintf_func;
  const char *oparg = *opcode_args;

  switch (*oparg)
    {
    case 'V': /* RVV */
      switch (*++oparg)
	{
	case 'd':
	  print (info->stream, "%s",
		 riscv_vecr_names_numeric[EXTRACT_OPERAND (VD, l)]);
	  break;

	case 's':
	  print (info->stream, "%s",
		 riscv_vecr_names_numeric[EXTRACT_OPERAND (VS1, l)]);
	  break;

	case 't':
	  print (info->stream, "%s",
		 riscv_vecr_names_numeric[EXTRACT_OPERAND (VS2, l)]);
	  break;

	case 'b':
	case 'c':
	  {
	    int imm = (*oparg == 'b') ? EXTRACT_RVV_VB_IMM (l)
				      : EXTRACT_RVV_VC_IMM (l);
	    unsigned int imm_vlmul = EXTRACT_OPERAND (VLMUL, imm);
	    unsigned int imm_vsew = EXTRACT_OPERAND (VSEW, imm);
	    unsigned int imm_vta = EXTRACT_OPERAND (VTA, imm);
	    unsigned int imm_vma = EXTRACT_OPERAND (VMA, imm);
	    unsigned int imm_vtype_res = EXTRACT_OPERAND (VTYPE_RES, imm);

	    if (imm_vsew < ARRAY_SIZE (riscv_vsew)
		&& imm_vlmul < ARRAY_SIZE (riscv_vlmul)
		&& imm_vta < ARRAY_SIZE (riscv_vta)
		&& imm_vma < ARRAY_SIZE (riscv_vma)
		&& ! imm_vtype_res)
	      print (info->stream, "%s,%s,%s,%s", riscv_vsew[imm_vsew],
		     riscv_vlmul[imm_vlmul], riscv_vta[imm_vta],
		     riscv_vma[imm_vma]);
	    else
	      print (info->stream, "%d", imm);
	  }
	  break;

	case 'j':
	  print (info->stream, "%d", (int)EXTRACT_RVV_VI_UIMM (l));
	  break;

	case 'm':
	  if (! EXTRACT_OPERAND (VMASK, l))
	      print (info->stream, ",%s", riscv_vecm_names_numeric[0]);
	  break;

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
