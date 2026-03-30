global ft_atoi_base

ft_atoi_base:
	PUSH rbx
	PUSH r8
	PUSH r9

	MOV rdx,rsi		; put start of base string into register D
	MOV rax,0		; initialize register A to 0

_strlenLoop:
	CMP byte [rdx],0
	JE _baseCheck
	INC rax
	INC rdx

	JMP _strlenLoop

_baseCheck:
	MOV rbx,rax		; store value of base string length in register B
	CMP rbx,2		; check if base is at least 2
	JL _errorEnd

	MOV rdx,rsi		; Register D holds pointer to start of the base string

	_baseCheckLoop:

		MOV al, byte [rdx]	; subset of register A holds the current character's value

		CMP al,0	; iterate over base string
		JE _atoiSetUp

		CMP al,'+'	; check if char is +
		JE _errorEnd

		CMP al,'-'	; check if char is -
		JE _errorEnd

		CMP al,' '	; check if char is space or lower (whitespace)
		JLE _errorEnd

		MOV rcx,rdx
		INC rcx				; Register C holds pointer to next character in base string

			_baseCheckCompareLoop:

			CMP byte [rcx],0		; while (*nextChar)
			JE _baseCheckCompareLoopEnd

			CMP al, byte [rcx]	; if two characters are identical, return error
			JE _errorEnd

			INC rcx						; else increment and check until end of base string

			JMP _baseCheckCompareLoop

	_baseCheckCompareLoopEnd:

		INC rdx

		JMP _baseCheckLoop

_atoiSetUp:
	MOV rax,0	; Register A will contains the result of the atoi, initialized at 0
	MOV rcx,rdi	; Register C still contains a pointer to numStr start, extracted from argument 1

_atoiLoop:
	CMP byte [rcx],0
	JE _end
	MOV r8,0			; Register 8 will contain the index of the current num character in the base string
						; not using Register D cuz it gets wiped during multiplication operations

	_baseLoop:
		MOV r9b, byte [rsi + r8]	; Register 9 contains the value at current base string

		CMP r9b,0		; check if baseString is over
		JE _errorEnd	; if so, current character is not in the base

		CMP byte [rcx],r9b
		JE _baseLoopEnd

		INC r8			; Increment base string
		JMP _baseLoop

	_baseLoopEnd:
		MUL rbx			; multiply register A by the base length
		ADD rax, r8		; add index in the base string as value to result
		INC rcx			; increment numStr
		JMP _atoiLoop

_end:
					; Register A contains the calculated result
	POP rbx
	POP r8
	POP r9
	RET

_errorEnd:
	MOV rax,0		; Register A is set at 0 to return 0
	JMP _end

section .note.GNU-stack noalloc noexec nowrite progbits
