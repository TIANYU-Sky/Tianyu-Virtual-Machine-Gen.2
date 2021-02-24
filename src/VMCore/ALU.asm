.DATA

.CODE

inc_asm PROC	; INC指令

	; RCX：source
	; RDX：__PTR__ flag
	; RAX：return

	inc RCX
	pushfq
	pop qword ptr [RDX]
	mov RAX, RCX

	ret

inc_asm ENDP

dec_asm PROC	; DEC指令

	; RCX：source
	; RDX：__PTR__ flag
	; RAX：return

	dec RCX
	pushfq
	pop qword ptr [RDX]
	mov RAX, RCX

	ret

dec_asm ENDP

neg_asm PROC	; NEG指令

	; RCX：source
	; RDX：__PTR__ flag
	; RAX：return

	neg RCX
	pushfq
	pop qword ptr [RDX]
	mov RAX, RCX

	ret

neg_asm ENDP

not_asm PROC	; NOT指令

	; RCX：source
	; RDX：__PTR__ flag
	; RAX：return

	not RCX
	pushfq
	pop qword ptr [RDX]
	mov RAX, RCX

	ret

not_asm ENDP

add_asm PROC	; ADD指令

	; RCX：add1
	; RDX：add2
	; R8：__PTR__ flag
	; RAX：return

	mov RAX, RCX
	add RAX, RDX
	pushfq
	pop qword ptr [R8]

	ret

add_asm ENDP

sub_asm PROC	; SUB指令

	; RCX：minude
	; RDX：subtr
	; R8：__PTR__ flag
	; RAX：return

	mov RAX, RCX
	sub RAX, RDX
	pushfq
	pop qword ptr [R8]

	ret

sub_asm ENDP

cmp_asm PROC	; SUB指令

	; RCX：cmp1
	; RDX：cmp2
	; R8：__PTR__ flag

	cmp RCX, RDX
	pushfq
	pop qword ptr [R8]

	ret

cmp_asm ENDP

mul_asm PROC	; MUL指令

	; RCX：mul1
	; RDX：mul2
	; R8：__PTR__ mulH
	; R9：__PTR__ mulL
	; RAX：return-flag

	mov RAX, RCX
	mul RDX
	pushfq
	mov qword ptr[R8], RDX
	mov qword ptr[R9], RAX
	pop RAX

	ret

mul_asm ENDP

imul_asm PROC	; IMUL指令

	; RCX：mul1
	; RDX：mul2
	; R8：__PTR__ mulH
	; R9：__PTR__ mulL
	; RAX：return-flag

	mov RAX, RCX
	imul RDX
	pushfq
	mov qword ptr[R8], RDX
	mov qword ptr[R9], RAX
	pop RAX

	ret

imul_asm ENDP

div_asm PROC	; DIV指令

	; RCX：dividend1
	; RDX：divisor
	; R8：__PTR__ consult
	; R9：__PTR__ remainder
	; RAX：return-flag

	mov R10, RDX	; 保存RDX
	mov RAX, RCX	; 移动被除数至RAX
	xor RDX, RDX	; 清空RDX
	div R10
	pushfq
	mov qword ptr[R8], RAX
	mov qword ptr[R9], RDX
	pop RAX

	ret

div_asm ENDP

idiv_asm PROC	; IDIV指令

	; RCX：dividend1
	; RDX：divisor
	; R8：__PTR__ consult
	; R9：__PTR__ remainder
	; RAX：return-flag

	mov R10, RDX	; 保存RDX
	mov RAX, RCX	; 移动被除数至RAX
	cqo				; 扩展RAX（RAX>=0:RDX=0 | RAX<0:RDX=2^64-1）
	idiv R10
	pushfq
	mov qword ptr[R8], RAX
	mov qword ptr[R9], RDX
	pop RAX

	ret

idiv_asm ENDP

and_asm PROC	; AND指令

	; RCX：op1
	; RDX：op2
	; R8：__PTR__ flag
	; RAX：return

	mov RAX, RCX
	and RAX, RDX
	pushfq
	pop qword ptr [R8]

	ret

and_asm ENDP

or_asm PROC	; OR指令

	; RCX：op1
	; RDX：op2
	; R8：__PTR__ flag
	; RAX：return

	mov RAX, RCX
	or RAX, RDX
	pushfq
	pop qword ptr [R8]

	ret

or_asm ENDP

xor_asm PROC	; XOR指令

	; RCX：op1
	; RDX：op2
	; R8：__PTR__ flag
	; RAX：return

	mov RAX, RCX
	xor RAX, RDX
	pushfq
	pop qword ptr [R8]

	ret
xor_asm ENDP

shr_asm PROC	; SHR指令

	; RCX：op1
	; RDX：op2
	; R8：__PTR__ flag
	; RAX：return

	mov RAX, RCX
	mov RCX, RDX
	shr RAX, CL
	pushfq
	pop qword ptr [R8]

	ret

shr_asm ENDP

sar_asm PROC	; SAR指令

	; RCX：op1
	; RDX：op2
	; R8：__PTR__ flag
	; RAX：return

	mov RAX, RCX
	mov RCX, RDX
	sar RAX, CL
	pushfq
	pop qword ptr [R8]

	ret

sar_asm ENDP

shl_asm PROC	; SHL指令

	; RCX：op1
	; RDX：op2
	; R8：__PTR__ flag
	; RAX：return

	mov RAX, RCX
	mov RCX, RDX
	shl RAX, CL
	pushfq
	pop qword ptr [R8]

	ret

shl_asm ENDP

sal_asm PROC	; SAL指令

	; RCX：op1
	; RDX：op2
	; R8：__PTR__ flag
	; RAX：return

	mov RAX, RCX
	mov RCX, RDX
	sal RAX, CL
	pushfq
	pop qword ptr [R8]

	ret

sal_asm ENDP

END