	.text
	.intel_syntax noprefix
	.file	"ft_strlen.c"
	.globl	ft_strlen                       # -- Begin function ft_strlen
	.p2align	4, 0x90
	.type	ft_strlen,@function
ft_strlen:                              # @ft_strlen
	.cfi_startproc
# %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	mov	qword ptr [rbp - 8], rdi
	mov	dword ptr [rbp - 12], 0
.LBB0_1:                                # =>This Inner Loop Header: Depth=1
	mov	rax, qword ptr [rbp - 8]
	mov	rcx, rax
	add	rcx, 1
	mov	qword ptr [rbp - 8], rcx
	cmp	byte ptr [rax], 0
	je	.LBB0_3
# %bb.2:                                #   in Loop: Header=BB0_1 Depth=1
	mov	eax, dword ptr [rbp - 12]
	add	eax, 1
	mov	dword ptr [rbp - 12], eax
	jmp	.LBB0_1
.LBB0_3:
	movsxd	rax, dword ptr [rbp - 12]
	pop	rbp
	.cfi_def_cfa rsp, 8
	ret
.Lfunc_end0:
	.size	ft_strlen, .Lfunc_end0-ft_strlen
	.cfi_endproc
                                        # -- End function
	.ident	"Ubuntu clang version 12.0.1-19ubuntu3"
	.section	".note.GNU-stack","",@progbits
	.addrsig
