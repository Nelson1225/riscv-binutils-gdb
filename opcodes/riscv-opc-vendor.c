/* RISC-V vendor opcode list
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

#include "opcode/riscv.h"
#include "opcode/riscv-vendor.h"

const char * const riscv_vecr_names_numeric[NVECR] =
{
  "v0",   "v1",   "v2",   "v3",   "v4",   "v5",   "v6",   "v7",
  "v8",   "v9",   "v10",  "v11",  "v12",  "v13",  "v14",  "v15",
  "v16",  "v17",  "v18",  "v19",  "v20",  "v21",  "v22",  "v23",
  "v24",  "v25",  "v26",  "v27",  "v28",  "v29",  "v30",  "v31"
};

const char * const riscv_vecm_names_numeric[NVECM] =
{
  "v0.t"
};

/* List of vsetvli vsew constants.  */
const char * const riscv_vsew[8] =
{
  "e8", "e16", "e32", "e64", "e128", "e256", "e512", "e1024"
};

/* List of vsetvli vlmul constants.  */
const char * const riscv_vlmul[8] =
{
  "m1", "m2", "m4", "m8", 0, "mf8", "mf4", "mf2"
};

const char * const riscv_vta[2] =
{
  "tu", "ta"
};

const char * const riscv_vma[2] =
{
  "mu", "ma"
};

const struct riscv_opcode riscv_unratified_opcodes[] =
{
/* name, xlen, isa, operands, match, mask, match_func, pinfo.  */
{"vsetvl",        0, INSN_CLASS_V,  "d,s,t",  MATCH_VSETVL, MASK_VSETVL, match_opcode, 0},
{"vsetvli",       0, INSN_CLASS_V,  "d,s,Vc", MATCH_VSETVLI, MASK_VSETVLI, match_opcode, 0},
{"vsetivli",      0, INSN_CLASS_V,  "d,Z,Vb", MATCH_VSETIVLI, MASK_VSETIVLI, match_opcode, 0},

{"vlseg2e8.v",    0, INSN_CLASS_V_OR_ZVLSSEG,  "Vd,0(s)Vm", MATCH_VLSEG2E8V, MASK_VLSEG2E8V, match_opcode, INSN_DREF },
{"vsseg2e8.v",    0, INSN_CLASS_V_OR_ZVLSSEG,  "Vd,0(s)Vm", MATCH_VSSEG2E8V, MASK_VSSEG2E8V, match_opcode, INSN_DREF },
{"vloxseg2ei8.v", 0, INSN_CLASS_V_OR_ZVLSSEG,  "Vd,0(s),VtVm", MATCH_VLOXSEG2EI8V, MASK_VLOXSEG2EI8V, match_opcode, INSN_DREF },
{"vsoxseg2ei8.v", 0, INSN_CLASS_V_OR_ZVLSSEG,  "Vd,0(s),VtVm", MATCH_VSOXSEG2EI8V, MASK_VSOXSEG2EI8V, match_opcode, INSN_DREF },

{"vnsrl.wv",      0, INSN_CLASS_V,  "Vd,Vt,VsVm", MATCH_VNSRLWV, MASK_VNSRLWV, match_opcode, 0 },
{"vnsrl.wx",      0, INSN_CLASS_V,  "Vd,Vt,sVm", MATCH_VNSRLWX, MASK_VNSRLWX, match_opcode, 0 },
{"vnsrl.wi",      0, INSN_CLASS_V,  "Vd,Vt,VjVm", MATCH_VNSRLWI, MASK_VNSRLWI, match_opcode, 0 },

/* Terminate the list.  */
{0, 0, INSN_CLASS_NONE, 0, 0, 0, 0, 0 },
};

const struct riscv_opcode riscv_sifive_opcodes[] =
{
/* name, xlen, isa, operands, match, mask, match_func, pinfo.  */
/* SiFive specific cache control instruction.  */
{"cflush.d.l1",   0, INSN_CLASS_XSFCACHE, "s",  MATCH_CFLUSH_D_L1, MASK_CFLUSH_D_L1, match_opcode, 0 },
{"cdiscard.d.l1", 0, INSN_CLASS_XSFCACHE, "s",  MATCH_CDISCARD_D_L1, MASK_CDISCARD_D_L1, match_opcode, 0 },
{"cflush.i.l1",   0, INSN_CLASS_XSFCACHE, "",   MATCH_CFLUSH_I_L1, MASK_CFLUSH_I_L1, match_opcode, 0 },

/* Terminate the list.  */
{0, 0, INSN_CLASS_NONE, 0, 0, 0, 0, 0 },
};

const struct riscv_opcode *riscv_vendor_opcodes[] =
{
  riscv_unratified_opcodes,
  riscv_sifive_opcodes,
  NULL
};
