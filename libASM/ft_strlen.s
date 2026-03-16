global ft_strlen			; make the ft_strlen function public / accessible by other programs

ft_strlen:
	; GET ARGUMENTS
	; use GCC calling convention to retrieve the arguments given to the function
	MOV rcx,rdi				; put first argument, start of the string, into register C
							; Using register C because can be used more freely than B
							; ie it is caller saved or volatile, and must not be preserved

	; INITIALIZE RESULT
	; The value returned by RET is the one contained in register A
	MOV rax,0				; intialize register A to 0

loop:
	CMP byte [rcx], 0		; compare the byte at memory address in register C to 0 (which is ASCII for NULL)
	JE endLoop				; if character is NULL, jump to end loop
							; else the program continues linearly
	INC rax					; increment register A (which contains the length of the word)
	INC rcx					; increment register C (which contains the address of the current character in the string)

	JMP loop				; start the loop again

endLoop:
	RET						; returns the value in register A

; to avoid annoying linker error, specifying the executable risks of the function
section .note.GNU-stack noalloc noexec nowrite progbits
