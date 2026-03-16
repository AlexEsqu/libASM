section .data

section .text

global ft_strlen


ft_strlen:
	; PROLOG
	; set aside stack space for the function
	PUSH rbp				; storing base pointer to the stack
	MOV rbp, rsp			; put the stack pointer to the base pointer

	; GET ARGUMENTS
	; use GCC calling convention to retrieve the arguments given to the function
	MOV rcx,rdi				; put first argument into register C

	; INITIALIZE RESULT
	; The return value of a function is contained in register A
	MOV rax,0				; intialize register A (int len = 0)

loop:
	; while (*str)
	CMP byte [rbx], 0		; compare the byte at memory address in register C to NULL (0)
	JE endLoop				; if character is null, jump to end loop
							; else the program continues linearly
	; len ++
	INC rax					; increment register A
	; str ++
	INC rbx					; increment register C
	JMP loop				; continue the loop

endLoop:
	; EPILOG
	; clean out the stack and return the stack pointer to initial state
	POP rbp					; retrieving base pointer
	RET





