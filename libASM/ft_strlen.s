global ft_strlen			; make the ft_strlen function public / accessible by other programs

ft_strlen:
	; GET ARGUMENTS
	; use C Linux calling convention for x86_64 to retrieve the arguments given to the function
	MOV rax,rdi				; put first argument, start of the string, into register A

	; INITIALIZE RESULT
	; The value returned by RET is the one contained in register C
	MOV rcx,0				; intialize register C to 0
							; Using register C because can be used more freely than B
							; ie it is caller saved or volatile, and must not be preserved
							; and traditionally used for counters
	; XOR rcx,rcx			; smaller sized operation to zero a register, alternative to MOV rcx,0

count_char:
	CMP byte [rax], 0		; compare the byte at memory address in register A to 0 (which is ASCII for NULL)
	JE endLoop				; if character is NULL, jump to end loop
							; else the program continues linearly
	INC rcx					; increment register C (which contains the length of the word)
	INC rax					; increment register A (which contains the address of the current character in the string)

	JMP count_char			; start the loop again

endLoop:
	RET						; returns the value in register A

; to avoid annoying linker error, specifying the executable risks of the function
section .note.GNU-stack noalloc noexec nowrite progbits
