#source: attr-merge-arch-03a.s
#source: attr-merge-arch-03b.s
#as:
#ld: -r -m[riscv_choose_ilp32_emul]
#warning_output: attr-merge-arch-03.l
#readelf: -A

Attribute Section: riscv
File Attributes
  Tag_RISCV_arch: "rv32i2p0_m2p0_xbar2p0_xfoo2p0"
