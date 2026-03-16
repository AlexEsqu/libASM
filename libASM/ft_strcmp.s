global ft_strcmp

ft_strcmp:
	; PRESERVE NON VOLATILE REGISTERS
	PUSH rbp

	; GET ARGUMENTS
	; use GCC calling convention to retrieve the arguments given to the function
	; in x86-64, non floats arguments are put into rdi, rsi, rdx, rcx, r8, r9, then the stack
	MOV rcx,rdi				; put first argument, address of start of string1, into register C
	MOV rdx,rsi				; put second argument, address of start of string2, into register D

loop:
	; COMPARE
	; can only compare if at least one value is held in a register
	MOV al, byte [rcx]		; moves value of current character of string1 into subset of register A
	MOV bl, byte [rdx]		; moves value of current character of string2 into subset of register B
	CMP al,bl				; compare the character in register A and the one pointed to by register D
	JNE endLoop				; if they are not equal, jump to end loop

	CMP al, 0				; compare the character in register A to 0 to check if string is over
	JE endLoop				; if string1 is over, jump to end loop

	INC rcx					; increment register A which contains current address in string1
	INC rdx					; increment register B which contains current address in string2
	JMP loop				; start the loop again

endLoop:
	SUB al, bl				; subtract value of character pointed to by register D from register A
	MOVSX rax,al

	; RETRIEVE NON VOLATILE
	POP rbp
	RET						; returns the value in register A

; to avoid annoying linker error, specifying the executable risks of the function
section .note.GNU-stack noalloc noexec nowrite progbits
