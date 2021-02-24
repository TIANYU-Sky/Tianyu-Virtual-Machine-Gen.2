.DATA

.CODE

fcmp_asm PROC

	; RCX£º__PTR__ op1
	; RDX£º__PTR__ op2
	; RAX£ºreturn-flag

	finit
	fld real8 ptr [RCX]
	fcom real8 ptr [RDX]
	fstsw AX
	sahf
	pushfq
	pop RAX

	ret

fcmp_asm ENDP

fadd_asm PROC

	; RCX£º__PTR__ op1
	; RDX£º__PTR__ op2
	; R8£º__PTR__ result
	; RAX£ºreturn-flag

	finit
	fld real8 ptr [RCX]
	fadd real8 ptr [RDX]
	fst real8 ptr [R8]
	fstsw AX
	sahf
	pushfq
	pop RAX

	ret

fadd_asm ENDP

fiadd_asm PROC

	; RCX£º__PTR__ op1
	; RDX£º__PTR__ op2
	; R8£º__PTR__ result
	; RAX£ºreturn-flag

	finit
	fld real8 ptr [RCX]
	fild qword ptr [RDX]
	fadd
	fst real8 ptr [R8]
	fstsw AX
	sahf
	pushfq
	pop RAX

	ret

fiadd_asm ENDP

fsub_asm PROC

	; RCX£º__PTR__ op1
	; RDX£º__PTR__ op2
	; R8£º__PTR__ result
	; RAX£ºreturn-flag

	finit
	fld real8 ptr [RCX]
	fsub real8 ptr [RDX]
	fst real8 ptr [R8]
	fstsw AX
	sahf
	pushfq
	pop RAX

	ret

fsub_asm ENDP

fsubr_asm PROC

	; RCX£º__PTR__ op1
	; RDX£º__PTR__ op2
	; R8£º__PTR__ result
	; RAX£ºreturn-flag

	finit
	fld real8 ptr [RCX]
	fsubr real8 ptr [RDX]
	fst real8 ptr [R8]
	fstsw AX
	sahf
	pushfq
	pop RAX

	ret

fsubr_asm ENDP

fisub_asm PROC

	; RCX£º__PTR__ op1
	; RDX£º__PTR__ op2
	; R8£º__PTR__ result
	; RAX£ºreturn-flag

	finit
	fld real8 ptr [RCX]
	fild qword ptr [RDX]
	fsub
	fst real8 ptr [R8]
	fstsw AX
	sahf
	pushfq
	pop RAX

	ret

fisub_asm ENDP

fisubr_asm PROC

	; RCX£º__PTR__ op1
	; RDX£º__PTR__ op2
	; R8£º__PTR__ result
	; RAX£ºreturn-flag

	finit
	fld real8 ptr [RCX]
	fild qword ptr [RDX]
	fsubr
	fst real8 ptr [R8]
	fstsw AX
	sahf
	pushfq
	pop RAX

	ret

fisubr_asm ENDP

fmul_asm PROC

	; RCX£º__PTR__ op1
	; RDX£º__PTR__ op2
	; R8£º__PTR__ result
	; RAX£ºreturn-flag

	finit
	fld real8 ptr [RCX]
	fmul real8 ptr [RDX]
	fst real8 ptr [R8]
	fstsw AX
	sahf
	pushfq
	pop RAX

	ret

fmul_asm ENDP

fimul_asm PROC

	; RCX£º__PTR__ op1
	; RDX£º__PTR__ op2
	; R8£º__PTR__ result
	; RAX£ºreturn-flag

	finit
	fld real8 ptr [RCX]
	fild qword ptr [RDX]
	fmul
	fst real8 ptr [R8]
	fstsw AX
	sahf
	pushfq
	pop RAX

	ret

fimul_asm ENDP

fdiv_asm PROC

	; RCX£º__PTR__ op1
	; RDX£º__PTR__ op2
	; R8£º__PTR__ result
	; RAX£ºreturn-flag

	finit
	fld real8 ptr [RCX]
	fdiv real8 ptr [RDX]
	fst real8 ptr [R8]
	fstsw AX
	sahf
	pushfq
	pop RAX

	ret

fdiv_asm ENDP

fdivr_asm PROC

	; RCX£º__PTR__ op1
	; RDX£º__PTR__ op2
	; R8£º__PTR__ result
	; RAX£ºreturn-flag

	finit
	fld real8 ptr [RCX]
	fdivr real8 ptr [RDX]
	fst real8 ptr [R8]
	fstsw AX
	sahf
	pushfq
	pop RAX

	ret

fdivr_asm ENDP

fidiv_asm PROC

	; RCX£º__PTR__ op1
	; RDX£º__PTR__ op2
	; R8£º__PTR__ result
	; RAX£ºreturn-flag

	finit
	fld real8 ptr [RCX]
	fild qword ptr [RDX]
	fdiv
	fst real8 ptr [R8]
	fstsw AX
	sahf
	pushfq
	pop RAX

	ret

fidiv_asm ENDP

fidivr_asm PROC

	; RCX£º__PTR__ op1
	; RDX£º__PTR__ op2
	; R8£º__PTR__ result
	; RAX£ºreturn-flag

	finit
	fld real8 ptr [RCX]
	fild qword ptr [RDX]
	fdivr
	fst real8 ptr [R8]
	fstsw AX
	sahf
	pushfq
	pop RAX

	ret

fidivr_asm ENDP

fchs_asm PROC

	; RCX£º__PTR__ op1
	; RAX£ºreturn-flag

	finit
	fld real8 ptr [RCX]
	fchs
	fst real8 ptr [RCX]
	fstsw AX
	sahf
	pushfq
	pop RAX

	ret

fchs_asm ENDP

fabs_asm PROC

	; RCX£º__PTR__ op1
	; RAX£ºreturn-flag

	finit
	fld real8 ptr [RCX]
	fabs
	fst real8 ptr [RCX]
	fstsw AX
	sahf
	pushfq
	pop RAX

	ret

fabs_asm ENDP

fsqrt_asm PROC

	; RCX£º__PTR__ op1
	; RAX£ºreturn-flag

	finit
	fld real8 ptr [RCX]
	fsqrt
	fst real8 ptr [RCX]
	fstsw AX
	sahf
	pushfq
	pop RAX
	
	ret

fsqrt_asm ENDP

fsin_asm PROC

	; RCX£º__PTR__ op1
	; RAX£ºreturn-flag

	finit
	fld real8 ptr [RCX]
	fsin
	fst real8 ptr [RCX]
	fstsw AX
	sahf
	pushfq
	pop RAX

	ret

fsin_asm ENDP

fcos_asm PROC

	; RCX£º__PTR__ op1
	; RAX£ºreturn-flag

	finit
	fld real8 ptr [RCX]
	fcos
	fst real8 ptr [RCX]
	fstsw AX
	sahf
	pushfq
	pop RAX
	
	ret

fcos_asm ENDP

END