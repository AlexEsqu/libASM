extern __errno_location ; grab errno location
extern ft_strlen
extern ft_strcpy
extern malloc
global ft_strdup

ft_strdup:
	; PROLOG - ALIGN THE STACK
	; to comply with Application Binary Interface (ABI), setting lower 4 bits of the stack to 0
	; to garantee that RSP % 16 == 0 now before the call, and then RSP % 16 == 8 on function entry
	; PUSH rbp		; equivalent to SUB rsp,8 and MOV [rsp],rbp
					; so adding 8 bits for

	; GET ARGUMENTS
	; use GCC calling convention stating non float arguments are stored in rdi, rsi, rdx, rcx, r8, r9, then the stack
	MOV rbx,rdi		; GET ARG 1 - put char pointer of originalString into register B to preserve it

	; GET STRING LENGTH
	MOV rdi,rbx		; char pointer of original string is still in register Destination Index
	CALL ft_strlen	; use ft_strlen to get the length of the string into register A
	INC rax			; add 1 byte for the '\0' terminating the string

	; ALLOCATE
	MOV rdi,rax		; put string length into the first argument register (register Destination Index)
	CALL malloc wrt ..plt	; call the libc malloc function (not recoding malloc, that's another project)

	; CHECK ALLOCATION
	CMP rax,0		; check the return value, ie the char pointer, is not 0 / NULL
	JE _errorExit	; if it is NULL, set errno and leave

	; COPY SOURCE STRING INTO DESTINATION
	MOV rdi,rax		; put the destination string as first argument
	MOV rsi,rbx		; put the original string as second argument
	CALL ft_strcpy	; copy source string into destination string AND put destination string pointer into register A

	; EPILOG - RETURN ORIGINAL VALUES
	; POP rbp			; retrieve the original base pointer

	RET			; register A already contains destination string which needs to be returned


_errorExit:
	NEG rax			; get absolute value of syscall return code (malloc making sys_mmap syscall)
	MOV rbx,rax		; move return code into register C
	CALL __errno_location wrt ..plt	; put address of errno into register A
	MOV [rax],rbx	; put return code value at address stored in register C (errno location)
	MOV rax,0		; put 0 as return value

	; EPILOG - RETURN ORIGINAL VALUES
	POP rbx			; retrieve the original value of register B
	POP rbp			; retrieve the original base pointer
	RET


section .note.GNU-stack noexec progbits





