	.file	"bufbomb.c"
	.text
	.globl	getxs
	.type	getxs, @function
getxs:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movl	$1, -4(%rbp)
	movl	$0, -8(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, -16(%rbp)
	jmp	.L2
.L8:
	call	__ctype_b_loc
	movq	(%rax), %rax
	movl	-24(%rbp), %edx
	movslq	%edx, %rdx
	addq	%rdx, %rdx
	addq	%rdx, %rax
	movzwl	(%rax), %eax
	movzwl	%ax, %eax
	andl	$4096, %eax
	testl	%eax, %eax
	je	.L2
	cmpl	$47, -24(%rbp)
	jle	.L3
	cmpl	$57, -24(%rbp)
	jg	.L3
	movl	-24(%rbp), %eax
	subl	$48, %eax
	movl	%eax, -20(%rbp)
	jmp	.L4
.L3:
	cmpl	$64, -24(%rbp)
	jle	.L5
	cmpl	$70, -24(%rbp)
	jg	.L5
	movl	-24(%rbp), %eax
	subl	$55, %eax
	movl	%eax, -20(%rbp)
	jmp	.L4
.L5:
	movl	-24(%rbp), %eax
	subl	$87, %eax
	movl	%eax, -20(%rbp)
.L4:
	cmpl	$0, -4(%rbp)
	je	.L6
	movl	-20(%rbp), %eax
	movl	%eax, -8(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L2
.L6:
	movq	-16(%rbp), %rax
	leaq	1(%rax), %rdx
	movq	%rdx, -16(%rbp)
	movl	-8(%rbp), %edx
	movl	%edx, %ecx
	sall	$4, %ecx
	movl	-20(%rbp), %edx
	addl	%ecx, %edx
	movb	%dl, (%rax)
	movl	$1, -4(%rbp)
.L2:
	call	getchar
	movl	%eax, -24(%rbp)
	cmpl	$-1, -24(%rbp)
	je	.L7
	cmpl	$10, -24(%rbp)
	jne	.L8
.L7:
	movq	-16(%rbp), %rax
	leaq	1(%rax), %rdx
	movq	%rdx, -16(%rbp)
	movb	$0, (%rax)
	movq	-40(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	getxs, .-getxs
	.globl	getbuf
	.type	getbuf, @function
getbuf:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	leaq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	getxs
	movl	$1, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	getbuf, .-getbuf
	.section	.rodata
.LC0:
	.string	"Type Hex string:"
.LC1:
	.string	"getbuf returned 0x%x\n"
	.text
	.globl	test
	.type	test, @function
test:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	call	getbuf
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	test, .-test
	.globl	main
	.type	main, @function
main:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$80, %rsp
	leaq	-80(%rbp), %rax
	andl	$4095, %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	cltq
	leaq	15(%rax), %rdx
	movl	$16, %eax
	subq	$1, %rax
	addq	%rdx, %rax
	movl	$16, %ecx
	movl	$0, %edx
	divq	%rcx
	imulq	$16, %rax, %rax
	subq	%rax, %rsp
	movq	%rsp, %rax
	addq	$15, %rax
	shrq	$4, %rax
	salq	$4, %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movl	$0, (%rax)
	movl	$0, %eax
	call	test
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	main, .-main
	.ident	"GCC: (GNU) 6.1.1 20160802"
	.section	.note.GNU-stack,"",@progbits
