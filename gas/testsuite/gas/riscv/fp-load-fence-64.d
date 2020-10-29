#as: -defsym __64_bit__=1 -mno-relax -march=rv64gqc_zfh
#source: fp-load-fence.s
#objdump: -dr -Mno-aliases

.*:[ 	]+file format .*


Disassembly of section .text:

0+000 <target>:
[ 	]+[0-9a-f]+:[ 	]+01059507[ 	]+flh[ 	]+fa0,16\(a1\)
[ 	]+[0-9a-f]+:[ 	]+0ff0000f[ 	]+fence[ 	]+iorw,iorw
[ 	]+[0-9a-f]+:[ 	]+00059507[ 	]+flh[ 	]+fa0,0\(a1\)
[ 	]+[0-9a-f]+:[ 	]+R_RISCV_LO12_I[ 	]+target
[ 	]+[0-9a-f]+:[ 	]+0ff0000f[ 	]+fence[ 	]+iorw,iorw
[ 	]+[0-9a-f]+:[ 	]+00000597[ 	]+auipc[ 	]+a1,0x0
[ 	]+[0-9a-f]+:[ 	]+R_RISCV_PCREL_HI20[ 	]+target
[ 	]+[0-9a-f]+:[ 	]+00059507[ 	]+flh[ 	]+fa0,0\(a1\).*
[ 	]+[0-9a-f]+:[ 	]+R_RISCV_PCREL_LO12_I[ 	]+.*
[ 	]+[0-9a-f]+:[ 	]+0ff0000f[ 	]+fence[ 	]+iorw,iorw
[ 	]+[0-9a-f]+:[ 	]+0105a507[ 	]+flw[ 	]+fa0,16\(a1\)
[ 	]+[0-9a-f]+:[ 	]+0ff0000f[ 	]+fence[ 	]+iorw,iorw
[ 	]+[0-9a-f]+:[ 	]+0005a507[ 	]+flw[ 	]+fa0,0\(a1\)
[ 	]+[0-9a-f]+:[ 	]+R_RISCV_LO12_I[ 	]+target
[ 	]+[0-9a-f]+:[ 	]+0ff0000f[ 	]+fence[ 	]+iorw,iorw
[ 	]+[0-9a-f]+:[ 	]+00000597[ 	]+auipc[ 	]+a1,0x0
[ 	]+[0-9a-f]+:[ 	]+R_RISCV_PCREL_HI20[ 	]+target
[ 	]+[0-9a-f]+:[ 	]+0005a507[ 	]+flw[ 	]+fa0,0\(a1\).*
[ 	]+[0-9a-f]+:[ 	]+R_RISCV_PCREL_LO12_I[ 	]+.*
[ 	]+[0-9a-f]+:[ 	]+0ff0000f[ 	]+fence[ 	]+iorw,iorw
[ 	]+[0-9a-f]+:[ 	]+0105b507[ 	]+fld[ 	]+fa0,16\(a1\)
[ 	]+[0-9a-f]+:[ 	]+0ff0000f[ 	]+fence[ 	]+iorw,iorw
[ 	]+[0-9a-f]+:[ 	]+0005b507[ 	]+fld[ 	]+fa0,0\(a1\)
[ 	]+[0-9a-f]+:[ 	]+R_RISCV_LO12_I[ 	]+target
[ 	]+[0-9a-f]+:[ 	]+0ff0000f[ 	]+fence[ 	]+iorw,iorw
[ 	]+[0-9a-f]+:[ 	]+00000597[ 	]+auipc[ 	]+a1,0x0
[ 	]+[0-9a-f]+:[ 	]+R_RISCV_PCREL_HI20[ 	]+target
[ 	]+[0-9a-f]+:[ 	]+0005b507[ 	]+fld[ 	]+fa0,0\(a1\).*
[ 	]+[0-9a-f]+:[ 	]+R_RISCV_PCREL_LO12_I[ 	]+.*
[ 	]+[0-9a-f]+:[ 	]+0ff0000f[ 	]+fence[ 	]+iorw,iorw
[ 	]+[0-9a-f]+:[ 	]+0105c507[ 	]+flq[ 	]+fa0,16\(a1\)
[ 	]+[0-9a-f]+:[ 	]+0ff0000f[ 	]+fence[ 	]+iorw,iorw
[ 	]+[0-9a-f]+:[ 	]+0005c507[ 	]+flq[ 	]+fa0,0\(a1\)
[ 	]+[0-9a-f]+:[ 	]+R_RISCV_LO12_I[ 	]+target
[ 	]+[0-9a-f]+:[ 	]+0ff0000f[ 	]+fence[ 	]+iorw,iorw
[ 	]+[0-9a-f]+:[ 	]+0105a507[ 	]+flw[ 	]+fa0,16\(a1\)
[ 	]+[0-9a-f]+:[ 	]+0ff0000f[ 	]+fence[ 	]+iorw,iorw
[ 	]+[0-9a-f]+:[ 	]+01012507[ 	]+flw[ 	]+fa0,16\(sp\)
[ 	]+[0-9a-f]+:[ 	]+0ff0000f[ 	]+fence[ 	]+iorw,iorw
[ 	]+[0-9a-f]+:[ 	]+2988[ 	]+c.fld[ 	]+fa0,16\(a1\)
[ 	]+[0-9a-f]+:[ 	]+0ff0000f[ 	]+fence[ 	]+iorw,iorw
[ 	]+[0-9a-f]+:[ 	]+2542[ 	]+c.fldsp[ 	]+fa0,16\(sp\)
[ 	]+[0-9a-f]+:[ 	]+0ff0000f[ 	]+fence[ 	]+iorw,iorw
