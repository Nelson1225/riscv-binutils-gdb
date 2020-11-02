#as: -mno-relax -march=rv32gc_zfh -mfpu-load-fence
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
[ 	]+[0-9a-f]+:[ 	]+6988[ 	]+c.flw[ 	]+fa0,16\(a1\)
[ 	]+[0-9a-f]+:[ 	]+0ff0000f[ 	]+fence[ 	]+iorw,iorw
[ 	]+[0-9a-f]+:[ 	]+6542[ 	]+c.flwsp[ 	]+fa0,16\(sp\)
[ 	]+[0-9a-f]+:[ 	]+0ff0000f[ 	]+fence[ 	]+iorw,iorw
