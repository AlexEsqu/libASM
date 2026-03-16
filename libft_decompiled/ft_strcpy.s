	.text
	.intel_syntax noprefix
	.file	"ft_strcpy.c"
	.globl	ft_strcpy                       # -- Begin function ft_strcpy
	.p2align	4, 0x90
	.type	ft_strcpy,@function
ft_strcpy:                              # @ft_strcpy
	.cfi_startproc
# %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	mov	qword ptr [rbp - 8], rdi
	mov	qword ptr [rbp - 16], rsi
	mov	rax, qword ptr [rbp - 8]
	mov	qword ptr [rbp - 24], rax
.LBB0_1:                                # =>This Inner Loop Header: Depth=1
	mov	rax, qword ptr [rbp - 16]
	cmp	byte ptr [rax], 0
	je	.LBB0_3
# %bb.2:                                #   in Loop: Header=BB0_1 Depth=1
	mov	rax, qword ptr [rbp - 16]
	mov	cl, byte ptr [rax]
	mov	rax, qword ptr [rbp - 24]
	mov	byte ptr [rax], cl
	mov	rax, qword ptr [rbp - 24]
	add	rax, 1
	mov	qword ptr [rbp - 24], rax
	mov	rax, qword ptr [rbp - 16]
	add	rax, 1
	mov	qword ptr [rbp - 16], rax
	jmp	.LBB0_1
.LBB0_3:
	mov	rax, qword ptr [rbp - 24]
	mov	byte ptr [rax], 0
	mov	rax, qword ptr [rbp - 8]
	pop	rbp
	.cfi_def_cfa rsp, 8
	ret
.Lfunc_end0:
	.size	ft_strcpy, .Lfunc_end0-ft_strcpy
	.cfi_endproc
                                        # -- End function
	.ident	"Ubuntu clang version 18.1.3 (1ubuntu1)"
	.section	".note.GNU-stack","",@progbits
	.addrsig
