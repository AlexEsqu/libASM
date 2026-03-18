extern __errno_location ; grab errno location
global ft_write

ft_write:
	MOV rax,1				; define the write syscall setup
	SYSCALL					; call syscall, which evaluate to write

	CMP rax,0				; check if an errno has been set
	JL _errorExit

	RET

_errorExit:
	NEG rax					; get absolute value of syscall return code
	MOV rcx,rax				; move return code into register C
	CALL __errno_location wrt ..plt	; put address of errno into register A
	MOV [rax],rcx			; put return code value at address stored in register C (errno location)
	MOV rax,-1				; put -1 as return value for write
	RET


section .note.GNU-stack noalloc noexec progbits
