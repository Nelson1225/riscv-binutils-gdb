target:
	vsetvl a0, a1, a2

	vsetvli a0, a1, 0
	vsetvli a0, a1, 0x7ff
	vsetvli a0, a1, e16, m2
	vsetvli a0, a1, e256, m8
	vsetvli a0, a1, e512, m8
	vsetvli a0, a1, e1024, m8
	vsetvli a0, a1, e1024, m1
	vsetvli a0, a1, e1024, mf2
	vsetvli a0, a1, e512, mf4
	vsetvli a0, a1, e256, mf8
	vsetvli a0, a1, e256, m2, ta
	vsetvli a0, a1, e256, m2, ma
	vsetvli a0, a1, e256, m2, tu
	vsetvli a0, a1, e256, m2, mu
	vsetvli a0, a1, e256, m2, ta, ma
	vsetvli a0, a1, e256, m2, tu, ma
	vsetvli a0, a1, e256, m2, ta, mu
	vsetvli a0, a1, e256, m2, tu, mu

	vsetivli a0, 0xb, 0
	vsetivli a0, 0xb, 0x3ff
	vsetivli a0, 0xb, e16, m2
	vsetivli a0, 0xb, e256, m8
	vsetivli a0, 0xb, e512, m8
	vsetivli a0, 0xb, e1024, m8
	vsetivli a0, 0xb, e1024, m1
	vsetivli a0, 0xb, e1024, mf2
	vsetivli a0, 0xb, e512, mf4
	vsetivli a0, 0xb, e256, mf8
	vsetivli a0, 0xb, e256, m2, ta
	vsetivli a0, 0xb, e256, m2, ma
	vsetivli a0, 0xb, e256, m2, tu
	vsetivli a0, 0xb, e256, m2, mu
	vsetivli a0, 0xb, e256, m2, ta, ma
	vsetivli a0, 0xb, e256, m2, tu, ma
	vsetivli a0, 0xb, e256, m2, ta, mu
	vsetivli a0, 0xb, e256, m2, tu, mu

	vlseg2e8.v v4, (a0)
	vlseg2e8.v v4, 0(a0)
	vlseg2e8.v v4, (a0), v0.t
	vsseg2e8.v v4, (a0)
	vsseg2e8.v v4, 0(a0)
	vsseg2e8.v v4, (a0), v0.t

	vloxseg2ei8.v v4, (a0), v12
	vloxseg2ei8.v v4, 0(a0), v12
	vloxseg2ei8.v v4, (a0), v12, v0.t
	vsoxseg2ei8.v v4, (a0), v12
	vsoxseg2ei8.v v4, 0(a0), v12
	vsoxseg2ei8.v v4, (a0), v12, v0.t

	vnsrl.wv v4, v8, v12
	vnsrl.wx v4, v8, a1
	vnsrl.wi v4, v8, 1
	vnsrl.wi v4, v8, 31
	vnsrl.wv v4, v8, v12, v0.t
	vnsrl.wx v4, v8, a1, v0.t
	vnsrl.wi v4, v8, 1, v0.t
	vnsrl.wi v4, v8, 31, v0.t
