/* riscv-vendor.h.  RISC-V vendor opcode list for GDB, the GNU debugger.
   Copyright (C) 2011-2021 Free Software Foundation, Inc.
   Contributed by Andrew Waterman

   This file is part of GDB, GAS, and the GNU binutils.

   GDB, GAS, and the GNU binutils are free software; you can redistribute
   them and/or modify them under the terms of the GNU General Public
   License as published by the Free Software Foundation; either version
   3, or (at your option) any later version.

   GDB, GAS, and the GNU binutils are distributed in the hope that they
   will be useful, but WITHOUT ANY WARRANTY; without even the implied
   warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See
   the GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; see the file COPYING3. If not,
   see <http://www.gnu.org/licenses/>.  */

#ifndef _RISCV_VENDOR_H_
#define _RISCV_VENDOR_H_

enum riscv_vendor_insn_class
{
  /* Unratified extensions.  */
  INSN_CLASS_V,
  INSN_CLASS_V_OR_ZVLSSEG,

  /* SiFive extensions.  */
  INSN_CLASS_XSFCACHE,

  INSN_CLASS_VENDOR_NUM
};

enum reg_vendor_class
{
  RCLASS_VECR,
  RCLASS_VECM,
  RCLASS_VENDOR_NUM,
};

#define NVECR 32
#define NVECM 1

extern const char * const riscv_vecr_names_numeric[NVECR];
extern const char * const riscv_vecm_names_numeric[NVECM];
extern const char * const riscv_vsew[8];
extern const char * const riscv_vlmul[8];
extern const char * const riscv_vta[2];
extern const char * const riscv_vma[2];
extern const struct riscv_opcode *riscv_vendor_opcodes[];

/* RVV fields.  */
#define OP_MASK_VD	0x1f
#define OP_SH_VD	7
#define OP_MASK_VS1	0x1f
#define OP_SH_VS1	15
#define OP_MASK_VS2	0x1f
#define OP_SH_VS2	20
#define OP_MASK_VIMM	0x1f
#define OP_SH_VIMM	15
#define OP_MASK_VMASK	0x1
#define OP_SH_VMASK	25
#define OP_MASK_VLMUL	0x7
#define OP_SH_VLMUL	0
#define OP_MASK_VSEW	0x7
#define OP_SH_VSEW	3
#define OP_MASK_VTA	0x1
#define OP_SH_VTA	6
#define OP_MASK_VMA	0x1
#define OP_SH_VMA	7
#define OP_MASK_VTYPE_RES	0x1
#define OP_SH_VTYPE_RES		10
/* RVV IMM encodings.  */
#define ENCODE_RVV_VB_IMM(x)	(RV_X(x, 0, 10) << 20)
#define ENCODE_RVV_VC_IMM(x)	(RV_X(x, 0, 11) << 20)
#define EXTRACT_RVV_VI_UIMM(x)	(RV_X(x, 15, 5))
#define EXTRACT_RVV_VB_IMM(x)	(RV_X(x, 20, 10))
#define EXTRACT_RVV_VC_IMM(x)	(RV_X(x, 20, 11))
#define VALID_RVV_VB_IMM(x)	(EXTRACT_RVV_VB_IMM(ENCODE_RVV_VB_IMM(x)) == (x))
#define VALID_RVV_VC_IMM(x)	(EXTRACT_RVV_VC_IMM(ENCODE_RVV_VC_IMM(x)) == (x))
/* RVV instruction.  */
#define MATCH_VSETVL		0x80007057
#define MASK_VSETVL		0xfe00707f
#define MATCH_VSETIVLI		0xc0007057
#define MASK_VSETIVLI		0xc000707f
#define MATCH_VSETVLI		0x00007057
#define MASK_VSETVLI		0x8000707f
#define MATCH_VLSEG2E8V		0x20000007
#define MASK_VLSEG2E8V		0xfdf0707f
#define MATCH_VSSEG2E8V		0x20000027
#define MASK_VSSEG2E8V		0xfdf0707f
#define MATCH_VLOXSEG2EI8V	0x2c000007
#define MASK_VLOXSEG2EI8V	0xfc00707f
#define MATCH_VSOXSEG2EI8V	0x2c000027
#define MASK_VSOXSEG2EI8V	0xfc00707f
#define MATCH_VNSRLWV		0xb0000057
#define MASK_VNSRLWV		0xfc00707f
#define MATCH_VNSRLWX		0xb0004057
#define MASK_VNSRLWX		0xfc00707f
#define MATCH_VNSRLWI		0xb0003057
#define MASK_VNSRLWI		0xfc00707f

/* SiFive specific cache control instruction.  */
#define MATCH_CFLUSH_D_L1	0xfc000073
#define MASK_CFLUSH_D_L1	0xfff07fff
#define MATCH_CDISCARD_D_L1	0xfc200073
#define MASK_CDISCARD_D_L1	0xfff07fff
#define MATCH_CFLUSH_I_L1	0xfc100073
#define MASK_CFLUSH_I_L1	0xffffffff

#endif /* _RISCV_VENDOR_H_ */
