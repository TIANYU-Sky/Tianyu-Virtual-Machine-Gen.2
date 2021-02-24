.DATA

.CODE

inc_asm PROC	; INCָ��

	; RCX��source
	; RDX��__PTR__ flag
	; RAX��return

	inc RCX
	pushfq
	pop qword ptr [RDX]
	mov RAX, RCX

	ret

inc_asm ENDP

dec_asm PROC	; DECָ��

	; RCX��source
	; RDX��__PTR__ flag
	; RAX��return

	dec RCX
	pushfq
	pop qword ptr [RDX]
	mov RAX, RCX

	ret

dec_asm ENDP

neg_asm PROC	; NEGָ��

	; RCX��source
	; RDX��__PTR__ flag
	; RAX��return

	neg RCX
	pushfq
	pop qword ptr [RDX]
	mov RAX, RCX

	ret

neg_asm ENDP

not_asm PROC	; NOTָ��

	; RCX��source
	; RDX��__PTR__ flag
	; RAX��return

	not RCX
	pushfq
	pop qword ptr [RDX]
	mov RAX, RCX

	ret

not_asm ENDP

add_asm PROC	; ADDָ��

	; RCX��add1
	; RDX��add2
	; R8��__PTR__ flag
	; RAX��return

	mov RAX, RCX
	add RAX, RDX
	pushfq
	pop qword ptr [R8]

	ret

add_asm ENDP

sub_asm PROC	; SUBָ��

	; RCX��minude
	; RDX��subtr
	; R8��__PTR__ flag
	; RAX��return

	mov RAX, RCX
	sub RAX, RDX
	pushfq
	pop qword ptr [R8]

	ret

sub_asm ENDP

cmp_asm PROC	; SUBָ��

	; RCX��cmp1
	; RDX��cmp2
	; R8��__PTR__ flag

	cmp RCX, RDX
	pushfq
	pop qword ptr [R8]

	ret

cmp_asm ENDP

mul_asm PROC	; MULָ��

	; RCX��mul1
	; RDX��mul2
	; R8��__PTR__ mulH
	; R9��__PTR__ mulL
	; RAX��return-flag

	mov RAX, RCX
	mul RDX
	pushfq
	mov qword ptr[R8], RDX
	mov qword ptr[R9], RAX
	pop RAX

	ret

mul_asm ENDP

imul_asm PROC	; IMULָ��

	; RCX��mul1
	; RDX��mul2
	; R8��__PTR__ mulH
	; R9��__PTR__ mulL
	; RAX��return-flag

	mov RAX, RCX
	imul RDX
	pushfq
	mov qword ptr[R8], RDX
	mov qword ptr[R9], RAX
	pop RAX

	ret

imul_asm ENDP

div_asm PROC	; DIVָ��

	; RCX��dividend1
	; RDX��divisor
	; R8��__PTR__ consult
	; R9��__PTR__ remainder
	; RAX��return-flag

	mov R10, RDX	; ����RDX
	mov RAX, RCX	; �ƶ���������RAX
	xor RDX, RDX	; ���RDX
	div R10
	pushfq
	mov qword ptr[R8], RAX
	mov qword ptr[R9], RDX
	pop RAX

	ret

div_asm ENDP

idiv_asm PROC	; IDIVָ��

	; RCX��dividend1
	; RDX��divisor
	; R8��__PTR__ consult
	; R9��__PTR__ remainder
	; RAX��return-flag

	mov R10, RDX	; ����RDX
	mov RAX, RCX	; �ƶ���������RAX
	cqo				; ��չRAX��RAX>=0:RDX=0 | RAX<0:RDX=2^64-1��
	idiv R10
	pushfq
	mov qword ptr[R8], RAX
	mov qword ptr[R9], RDX
	pop RAX

	ret

idiv_asm ENDP

and_asm PROC	; ANDָ��

	; RCX��op1
	; RDX��op2
	; R8��__PTR__ flag
	; RAX��return

	mov RAX, RCX
	and RAX, RDX
	pushfq
	pop qword ptr [R8]

	ret

and_asm ENDP

or_asm PROC	; ORָ��

	; RCX��op1
	; RDX��op2
	; R8��__PTR__ flag
	; RAX��return

	mov RAX, RCX
	or RAX, RDX
	pushfq
	pop qword ptr [R8]

	ret

or_asm ENDP

xor_asm PROC	; XORָ��

	; RCX��op1
	; RDX��op2
	; R8��__PTR__ flag
	; RAX��return

	mov RAX, RCX
	xor RAX, RDX
	pushfq
	pop qword ptr [R8]

	ret
xor_asm ENDP

shr_asm PROC	; SHRָ��

	; RCX��op1
	; RDX��op2
	; R8��__PTR__ flag
	; RAX��return

	mov RAX, RCX
	mov RCX, RDX
	shr RAX, CL
	pushfq
	pop qword ptr [R8]

	ret

shr_asm ENDP

sar_asm PROC	; SARָ��

	; RCX��op1
	; RDX��op2
	; R8��__PTR__ flag
	; RAX��return

	mov RAX, RCX
	mov RCX, RDX
	sar RAX, CL
	pushfq
	pop qword ptr [R8]

	ret

sar_asm ENDP

shl_asm PROC	; SHLָ��

	; RCX��op1
	; RDX��op2
	; R8��__PTR__ flag
	; RAX��return

	mov RAX, RCX
	mov RCX, RDX
	shl RAX, CL
	pushfq
	pop qword ptr [R8]

	ret

shl_asm ENDP

sal_asm PROC	; SALָ��

	; RCX��op1
	; RDX��op2
	; R8��__PTR__ flag
	; RAX��return

	mov RAX, RCX
	mov RCX, RDX
	sal RAX, CL
	pushfq
	pop qword ptr [R8]

	ret

sal_asm ENDP

END