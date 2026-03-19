global ft_atoi_base

ft_atoi_base:
	PUSH rbx
	PUSH r8
	PUSH r9

	; GET ARGUMENTS
	; use GCC calling convention to retrieve the arguments given to the function
	; in x86-64, non floats arguments are put into rdi, rsi, rdx, rcx, r8, r9, then the stack
	MOV rcx,rdi				; put first argument, address of start of numStr, into register C
	MOV rdx,rsi				; put second argument, address of start of baseStr, into register D

	MOV rax,0

_strlenLoop:
	CMP byte [rdx],0
	JE _atoiSetUp
	INC rax
	INC rdx

	JMP _strlenLoop

_atoiSetUp:
	MOV rbx,rax	; Register B contains the length of the baseStr
	MOV rax,0	; Register A contains the result of the atoi, initialized at 0
				; Register C still contains a pointer to numStr start

_atoiLoop:
	CMP byte [rcx],0
	JE _endAtoiLoop
	MOV r8,0			; Register D will contain the index of the current num character in the base string

	_baseLoop:
		MOV r9b, byte [rsi + r8]	; Register 9 contains the value at current base string

		CMP byte [rcx],r9b
		JE _baseLoopEnd

		INC r8			; Increment base string
		JMP _baseLoop

	_baseLoopEnd:

		MUL rbx			; multiply register A by the base length
		ADD rax, r8	; add index in the base string as value to result
		INC rcx			; increment numStr
		JMP _atoiLoop

_endAtoiLoop:
	POP rbx
	POP r8
	POP r9
	RET

section .note.GNU-stack noalloc noexec nowrite progbits
