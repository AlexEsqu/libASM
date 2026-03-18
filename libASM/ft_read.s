extern __errno_location ; grab errno location
global ft_read

ft_read:

	; GET ARGUMENTS
	; use GCC calling convention stating non float arguments are stored in rdi, rsi, rdx, rcx, r8, r9, then the stack
					; ARG 1 - keep file descriptor into register Destination Index (RDI)
					; ARG 2 - keep destination buffer into register Source Index (RSI)
					; ARG 3 - keep byte count in register D (RDX)
	; since the read() libc function already fits the GCC calling convention

	; READ
	MOV rax,0				; set the syscall code for sys_read
	SYSCALL					; call syscall using the arguments set into register A, D, SI and DI

	; ERROR HANDLING
	CMP rax,0				; check if an errno has been set
	JL _errorExit

	RET

_errorExit:
	NEG rax					; get absolute value of syscall return code
	MOV rcx,rax				; move return code into register C
	CALL __errno_location wrt ..plt	; put address of errno into register A
	MOV [rax],rcx			; put return code value at address stored in register C (errno location)
	MOV rax,-1				; put -1 as return value for read
	RET


; to avoid annoying linker error, specifying the executable risks of the function
section .note.GNU-stack noalloc noexec nowrite progbits
