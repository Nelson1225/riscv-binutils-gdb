#as: -march=rv64ib -defsym __64_bit__=1
#source: zext.s
#objdump: -d

.*:[ 	]+file format .*


Disassembly of section .text:

0+000 <target>:
[ 	]+0:[ 	]+0ff5f513[ 	]+zext.b[ 	]+a0,a1
[ 	]+4:[ 	]+0805c53b[ 	]+zext.h[ 	]+a0,a1
[ 	]+8:[ 	]+0805c533[ 	]+zext.w[ 	]+a0,a1
[ 	]+c:[ 	]+0005851b[ 	]+sext.w[ 	]+a0,a1
