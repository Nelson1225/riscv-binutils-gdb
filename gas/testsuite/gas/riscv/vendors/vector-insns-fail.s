# Vector Unit-Stride Segment Loads and Stores

	vlseg2e8.v v0, (a0), v0.t	# vd overlap vm
	vsseg2e8.v v0, (a0), v0.t	# vd overlap vm

# Vector Ordered Indexed Segment Loads and Stores

	vloxseg2ei8.v v4, (a0), v4		# vd overlap vs2
	vloxseg2ei8.v v0, (a0), v4, v0.t	# vd overlap vm
	vsoxseg2ei8.v v4, (a0), v4		# vd overlap vs2
	vsoxseg2ei8.v v0, (a0), v4, v0.t	# vd overlap vm

# Vector Narrowing Integer Right Shift Instructions

	vnsrl.wv v2, v2, v4		# vd overlap vs2
	vnsrl.wv v2, v3, v4		# vs2 should be multiple of 2
	vnsrl.wv v3, v2, v4		# vd overlap vs2
	vnsrl.wv v4, v2, v4		# OK
	vnsrl.wv v0, v2, v4, v0.t	# vd overlap vm
	vnsrl.wx v2, v2, a1		# vd overlap vs2
	vnsrl.wx v2, v3, a1		# vs2 should be multiple of 2
	vnsrl.wx v3, v2, a1		# vd overlap vs2
	vnsrl.wx v0, v2, a1, v0.t	# vd overlap vm
	vnsrl.wi v2, v2, 31		# vd overlap vs2
	vnsrl.wi v2, v3, 31		# vs2 should be multiple of 2
	vnsrl.wi v3, v2, 31		# vd overlap vs2
	vnsrl.wi v0, v2, 31, v0.t	# vd overlap vm
