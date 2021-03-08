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
			insn_t l ATTRIBUTE_UNUSED,
			disassemble_info *info ATTRIBUTE_UNUSED)
{
  const char *oparg = *opcode_args;

  switch (*oparg)
    {
    default:
      return FALSE;
    }

  *opcode_args = oparg;
  return TRUE;
}
