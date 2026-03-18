extern __errno_location ; grab errno location
extern ft_strlen
extern ft_strcpy
extern malloc
global ft_strdup

ft_strdup:
	; GET ARGUMENTS
	; use GCC calling convention stating non float arguments are stored in rdi, rsi, rdx, rcx, r8, r9, then the stack
	MOV rcx,rdi		; ARG 1 - put char pointer of originalString into register C

	; GET STRING LENGTH
					; char pointer of original string is still in register Destination Index
	CALL ft_strlen	; use ft_strlen to get the length of the string into register A
	INC rax			; add 1 byte for the '\0' terminating the string

	; ALLOCATE
	MOV rdi,rax		; put string length into the first argument register (register Destination Index)
	CALL malloc		; call the libc malloc function (not recoding malloc, that's another project)

	; CHECK ALLOCATION
	CMP rax,0		; check the return value, ie the char pointer, is not 0 / NULL
	JE _errorExit	; if it is NULL, set errno and leave

	; COPY SOURCE STRING INTO DESTINATION
	MOV rdi,rax		; put the destination string as first argument
	MOV rsi,rcx		; put the original string as second argument

					; register A already contains destination string which needs to be returned
	RET


_errorExit:
	NEG rax			; get absolute value of syscall return code (malloc making sys_mmap syscall)
	MOV rcx,rax		; move return code into register C
	CALL __errno_location wrt ..plt	; put address of errno into register A
	MOV [rax],rcx	; put return code value at address stored in register C (errno location)
	MOV rax,-1		; put -1 as return value for write
	RET






