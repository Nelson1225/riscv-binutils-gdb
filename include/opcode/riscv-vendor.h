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
  /* SiFive extensions.  */
  INSN_CLASS_XSFCACHE,

  INSN_CLASS_VENDOR_NUM
};

enum reg_vendor_class
{
  RCLASS_VENDOR_NUM,
};

extern const struct riscv_opcode *riscv_vendor_opcodes[];

/* SiFive specific cache control instruction.  */
#define MATCH_CFLUSH_D_L1	0xfc000073
#define MASK_CFLUSH_D_L1	0xfff07fff
#define MATCH_CDISCARD_D_L1	0xfc200073
#define MASK_CDISCARD_D_L1	0xfff07fff
#define MATCH_CFLUSH_I_L1	0xfc100073
#define MASK_CFLUSH_I_L1	0xffffffff

#endif /* _RISCV_VENDOR_H_ */
