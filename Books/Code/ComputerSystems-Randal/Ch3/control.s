	.file	"control.c"
	.text
	.globl	asm_if
	.type	asm_if, @function
asm_if:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	cmpl	$0, -4(%rbp)
	jle	.L2
	addl	$4, -4(%rbp)
	jmp	.L3
.L2:
	subl	$1, -4(%rbp)
.L3:
	movl	-4(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	asm_if, .-asm_if
	.globl	asm_while
	.type	asm_while, @function
asm_while:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	jmp	.L6
.L7:
	subl	$1, -4(%rbp)
.L6:
	cmpl	$0, -4(%rbp)
	jne	.L7
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	asm_while, .-asm_while
	.globl	asm_for
	.type	asm_for, @function
asm_for:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp)
	movl	-20(%rbp), %eax
	movl	%eax, -4(%rbp)
	movl	$0, -8(%rbp)
	jmp	.L9
.L10:
	movl	-20(%rbp), %eax
	addl	%eax, -4(%rbp)
	addl	$1, -8(%rbp)
.L9:
	movl	-8(%rbp), %eax
	cmpl	-20(%rbp), %eax
	jl	.L10
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	asm_for, .-asm_for
	.globl	asm_switch
	.type	asm_switch, @function
asm_switch:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	cmpl	$5, -4(%rbp)
	ja	.L12
	movl	-4(%rbp), %eax
	movq	.L14(,%rax,8), %rax
	jmp	*%rax
	.section	.rodata
	.align 8
	.align 4
.L14:
	.quad	.L12
	.quad	.L13
	.quad	.L15
	.quad	.L16
	.quad	.L17
	.quad	.L18
	.text
.L13:
	addl	$1, -4(%rbp)
	jmp	.L19
.L15:
	subl	$1, -4(%rbp)
	jmp	.L19
.L16:
	movl	-4(%rbp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	movl	%eax, -4(%rbp)
	jmp	.L19
.L17:
	addl	$10, -4(%rbp)
	jmp	.L19
.L18:
	subl	$10, -4(%rbp)
	jmp	.L19
.L12:
	sall	-4(%rbp)
.L19:
	movl	-4(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	asm_switch, .-asm_switch
	.globl	short_switch
	.type	short_switch, @function
short_switch:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %eax
	cmpl	$1, %eax
	je	.L23
	cmpl	$2, %eax
	je	.L24
	jmp	.L27
.L23:
	addl	$1, -4(%rbp)
	jmp	.L25
.L24:
	subl	$1, -4(%rbp)
	jmp	.L25
.L27:
	sall	-4(%rbp)
.L25:
	movl	-4(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	short_switch, .-short_switch
	.globl	short_if
	.type	short_if, @function
short_if:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L29
	addl	$1, -4(%rbp)
	jmp	.L30
.L29:
	cmpl	$2, -4(%rbp)
	jne	.L31
	subl	$1, -4(%rbp)
	jmp	.L30
.L31:
	sall	-4(%rbp)
.L30:
	movl	-4(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	short_if, .-short_if
	.ident	"GCC: (GNU) 6.3.1 20170306"
	.section	.note.GNU-stack,"",@progbits
