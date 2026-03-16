global ft_strcpy

ft_strcpy:
	; GET ARGUMENTS
	; use GCC calling convention to retrieve the arguments given to the function
	; in x86-64, non floats arguments are put into rdi, rsi, rdx, rcx, r8, r9, then the stack
	MOV rcx,rdi				; place pointer to destination string in register D
	MOV rdx,rsi				; place pointer to source string in register C

loop:
	MOV al, byte [rdx]		; Put the current source string character into a subset of register A
	CMP al,0				; Check if current character is NULL
	JE endLoop				; if so quit loop

	MOV byte [rcx],al		; Put the subset of register A into the current destination character
	INC rdx					; increment pointer to source string
	INC rcx					; increment pointer to destination string

	JMP loop				; continue loop

endLoop:
	MOV rax,rcx
	RET						; end the function

; to avoid annoying linker error, specifying the executable risks of the function
section .note.GNU-stack noalloc noexec nowrite progbits

