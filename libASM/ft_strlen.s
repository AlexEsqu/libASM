section .data

section .text

global ft_strlen

ft_strlen:
	; GET ARGUMENTS
	; use GCC calling convention to retrieve the arguments given to the function
	MOV rcx,rdi				; put first argument into register C
							; Register C can be used more freely than B

	; INITIALIZE RESULT
	; The return value of a function is contained in register A
	MOV rax,0				; intialize register A
							; Register A is used for return values

loop:
	; while (*str)
	CMP byte [rcx], 0		; compare the byte at memory address in register C to NULL (0)
	JE endLoop				; if character is null, jump to end loop
							; else the program continues linearly
	; len ++
	INC rax					; increment register A
	; str ++
	INC rcx					; increment register C
	JMP loop				; continue the loop

endLoop:
	RET

; to avoid annoying linker error, specifying the executable risks of the function
section .note.GNU-stack noalloc noexec nowrite progbits
