global ft_read

ft_read:
	; GET ARGUMENTS
	; use GCC calling convention stating non float arguments are stored in rdi, rsi, rdx, rcx, r8, r9, then the stack
					; ARG 1 - keep file descriptor into register Destination Index (RDI)
					; ARG 2 - keep destination buffer into register Source Index (RSI)
					; ARG 3 - keep byte count in register D (RDX)
	; since the read() libc function already fits the GCC calling convention

	MOV rax,0	; set the syscall code for sys_read
	SYSCALL		; call syscall using the arguments set into register A, D, SI and DI
