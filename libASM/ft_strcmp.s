global ft_strcmp

ft_strcmp:

	; PRESERVE
	; Since I use more than the three available volatile register, I preserve the non-volatile ones
	PUSH rbx				; put original value of register B on the stack

	; GET ARGUMENTS
	; use GCC calling convention to retrieve the arguments given to the function
	; in x86-64 : rdi, rsi, rdx, rcx, r8, r9, stack
	MOV rax,rdi				; put first argument, address of start of string1, into register A
	MOV rbx,rsi				; put second argument, address of start of string2, into register B

loop:
	; COMPARE
	; can only compare if at least one value is held in a register
	MOV rcx, qword [rax]	; moves value of current character of string1 into register C
	; MOV rdx, dword [rbx]	; moves value of current character of string2 into register D
	CMP rcx, qword [rbx]	; compare the bytes in register C and D

	JNE endLoop				; if they are not equal, jump to end loop

	INC rax					; increment register A which contains current address in string1
	INC rbx					; increment register B which contains current address in string2
	JMP loop				; start the loop again

endLoop:
	SUB rcx, qword [rbx]	; subtract  from register A
	MOV rax,rcx
	; RETRIEVE
	POP rbx					; retrieves the original value of register B

	; RETURN
	RET						; returns the value in register A

; to avoid annoying linker error, specifying the executable risks of the function
section .note.GNU-stack noalloc noexec nowrite progbits
