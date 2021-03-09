#as: -march=rv32iv1p0
#objdump: -dr

.*:[ 	]+file format .*


Disassembly of section .text:

0+000 <target>:
[ 	]+[0-9a-f]+:[ 	]+80c5f557[ 	]+vsetvl[ 	]+a0,a1,a2
[ 	]+[0-9a-f]+:[ 	]+0005f557[ 	]+vsetvli[ 	]+a0,a1,e8,m1,tu,mu
[ 	]+[0-9a-f]+:[ 	]+7ff5f557[ 	]+vsetvli[ 	]+a0,a1,2047
[ 	]+[0-9a-f]+:[ 	]+0095f557[ 	]+vsetvli[ 	]+a0,a1,e16,m2,tu,mu
[ 	]+[0-9a-f]+:[ 	]+02b5f557[ 	]+vsetvli[ 	]+a0,a1,e256,m8,tu,mu
[ 	]+[0-9a-f]+:[ 	]+0335f557[ 	]+vsetvli[ 	]+a0,a1,e512,m8,tu,mu
[ 	]+[0-9a-f]+:[ 	]+03b5f557[ 	]+vsetvli[ 	]+a0,a1,e1024,m8,tu,mu
[ 	]+[0-9a-f]+:[ 	]+0385f557[ 	]+vsetvli[ 	]+a0,a1,e1024,m1,tu,mu
[ 	]+[0-9a-f]+:[ 	]+03f5f557[ 	]+vsetvli[ 	]+a0,a1,e1024,mf2,tu,mu
[ 	]+[0-9a-f]+:[ 	]+0365f557[ 	]+vsetvli[ 	]+a0,a1,e512,mf4,tu,mu
[ 	]+[0-9a-f]+:[ 	]+02d5f557[ 	]+vsetvli[ 	]+a0,a1,e256,mf8,tu,mu
[ 	]+[0-9a-f]+:[ 	]+0695f557[ 	]+vsetvli[ 	]+a0,a1,e256,m2,ta,mu
[ 	]+[0-9a-f]+:[ 	]+0a95f557[ 	]+vsetvli[ 	]+a0,a1,e256,m2,tu,ma
[ 	]+[0-9a-f]+:[ 	]+0295f557[ 	]+vsetvli[ 	]+a0,a1,e256,m2,tu,mu
[ 	]+[0-9a-f]+:[ 	]+0295f557[ 	]+vsetvli[ 	]+a0,a1,e256,m2,tu,mu
[ 	]+[0-9a-f]+:[ 	]+0e95f557[ 	]+vsetvli[ 	]+a0,a1,e256,m2,ta,ma
[ 	]+[0-9a-f]+:[ 	]+0a95f557[ 	]+vsetvli[ 	]+a0,a1,e256,m2,tu,ma
[ 	]+[0-9a-f]+:[ 	]+0695f557[ 	]+vsetvli[ 	]+a0,a1,e256,m2,ta,mu
[ 	]+[0-9a-f]+:[ 	]+0295f557[ 	]+vsetvli[ 	]+a0,a1,e256,m2,tu,mu
[ 	]+[0-9a-f]+:[ 	]+c005f557[ 	]+vsetivli[ 	]+a0,11,e8,m1,tu,mu
[ 	]+[0-9a-f]+:[ 	]+fff5f557[ 	]+vsetivli[ 	]+a0,11,e1024,mf2,ta,ma
[ 	]+[0-9a-f]+:[ 	]+c095f557[ 	]+vsetivli[ 	]+a0,11,e16,m2,tu,mu
[ 	]+[0-9a-f]+:[ 	]+c2b5f557[ 	]+vsetivli[ 	]+a0,11,e256,m8,tu,mu
[ 	]+[0-9a-f]+:[ 	]+c335f557[ 	]+vsetivli[ 	]+a0,11,e512,m8,tu,mu
[ 	]+[0-9a-f]+:[ 	]+c3b5f557[ 	]+vsetivli[ 	]+a0,11,e1024,m8,tu,mu
[ 	]+[0-9a-f]+:[ 	]+c385f557[ 	]+vsetivli[ 	]+a0,11,e1024,m1,tu,mu
[ 	]+[0-9a-f]+:[ 	]+c3f5f557[ 	]+vsetivli[ 	]+a0,11,e1024,mf2,tu,mu
[ 	]+[0-9a-f]+:[ 	]+c365f557[ 	]+vsetivli[ 	]+a0,11,e512,mf4,tu,mu
[ 	]+[0-9a-f]+:[ 	]+c2d5f557[ 	]+vsetivli[ 	]+a0,11,e256,mf8,tu,mu
[ 	]+[0-9a-f]+:[ 	]+c695f557[ 	]+vsetivli[ 	]+a0,11,e256,m2,ta,mu
[ 	]+[0-9a-f]+:[ 	]+ca95f557[ 	]+vsetivli[ 	]+a0,11,e256,m2,tu,ma
[ 	]+[0-9a-f]+:[ 	]+c295f557[ 	]+vsetivli[ 	]+a0,11,e256,m2,tu,mu
[ 	]+[0-9a-f]+:[ 	]+c295f557[ 	]+vsetivli[ 	]+a0,11,e256,m2,tu,mu
[ 	]+[0-9a-f]+:[ 	]+ce95f557[ 	]+vsetivli[ 	]+a0,11,e256,m2,ta,ma
[ 	]+[0-9a-f]+:[ 	]+ca95f557[ 	]+vsetivli[ 	]+a0,11,e256,m2,tu,ma
[ 	]+[0-9a-f]+:[ 	]+c695f557[ 	]+vsetivli[ 	]+a0,11,e256,m2,ta,mu
[ 	]+[0-9a-f]+:[ 	]+c295f557[ 	]+vsetivli[ 	]+a0,11,e256,m2,tu,mu
[ 	]+[0-9a-f]+:[ 	]+22050207[ 	]+vlseg2e8.v[ 	]+v4,\(a0\)
[ 	]+[0-9a-f]+:[ 	]+22050207[ 	]+vlseg2e8.v[ 	]+v4,\(a0\)
[ 	]+[0-9a-f]+:[ 	]+20050207[ 	]+vlseg2e8.v[ 	]+v4,\(a0\),v0.t
[ 	]+[0-9a-f]+:[ 	]+22050227[ 	]+vsseg2e8.v[ 	]+v4,\(a0\)
[ 	]+[0-9a-f]+:[ 	]+22050227[ 	]+vsseg2e8.v[ 	]+v4,\(a0\)
[ 	]+[0-9a-f]+:[ 	]+20050227[ 	]+vsseg2e8.v[ 	]+v4,\(a0\),v0.t
[ 	]+[0-9a-f]+:[ 	]+2ec50207[ 	]+vloxseg2ei8.v[ 	]+v4,\(a0\),v12
[ 	]+[0-9a-f]+:[ 	]+2ec50207[ 	]+vloxseg2ei8.v[ 	]+v4,\(a0\),v12
[ 	]+[0-9a-f]+:[ 	]+2cc50207[ 	]+vloxseg2ei8.v[ 	]+v4,\(a0\),v12,v0.t
[ 	]+[0-9a-f]+:[ 	]+2ec50227[ 	]+vsoxseg2ei8.v[ 	]+v4,\(a0\),v12
[ 	]+[0-9a-f]+:[ 	]+2ec50227[ 	]+vsoxseg2ei8.v[ 	]+v4,\(a0\),v12
[ 	]+[0-9a-f]+:[ 	]+2cc50227[ 	]+vsoxseg2ei8.v[ 	]+v4,\(a0\),v12,v0.t
[ 	]+[0-9a-f]+:[ 	]+b2860257[ 	]+vnsrl.wv[ 	]+v4,v8,v12
[ 	]+[0-9a-f]+:[ 	]+b285c257[ 	]+vnsrl.wx[ 	]+v4,v8,a1
[ 	]+[0-9a-f]+:[ 	]+b280b257[ 	]+vnsrl.wi[ 	]+v4,v8,1
[ 	]+[0-9a-f]+:[ 	]+b28fb257[ 	]+vnsrl.wi[ 	]+v4,v8,31
[ 	]+[0-9a-f]+:[ 	]+b0860257[ 	]+vnsrl.wv[ 	]+v4,v8,v12,v0.t
[ 	]+[0-9a-f]+:[ 	]+b085c257[ 	]+vnsrl.wx[ 	]+v4,v8,a1,v0.t
[ 	]+[0-9a-f]+:[ 	]+b080b257[ 	]+vnsrl.wi[ 	]+v4,v8,1,v0.t
[ 	]+[0-9a-f]+:[ 	]+b08fb257[ 	]+vnsrl.wi[ 	]+v4,v8,31,v0.t
