global ft_atoi_base

ft_atoi_base:

	; GET ARGUMENTS
	; use GCC calling convention to retrieve the arguments given to the function
	; in x86-64, non floats arguments are put into rdi, rsi, rdx, rcx, r8, r9, then the stack
	; RDI holds char* numStr
	; RSI holds char* baseStr

	MOV rbx,rsi		; put start of base string into register B
	MOV rcx,0		; initialize register C to 0 => holding numString len

; checking the base provided is legit
_baseCheck:
	MOV al, byte [rbx]	; subset of register A holds currentBaseChar

	CMP al,0			; while (char currentBaseChar != '\0')
	JE _atoiSetUp

	CMP al,'+'			; if char currentBaseChar == '+' error
	JE _errorEnd

	CMP al,'-'			; if char currentBaseChar == '-' error
	JE _errorEnd

	CMP al,' '			; if char currentBaseChar <= ' ' error
	JLE _errorEnd

	MOV rdx,rbx
	INC rdx				; register D holds char* baseStr + 1

	_checkDuplicateLoop:
		CMP byte [rdx],0			; while (*nextBaseChar != 0)
		JE _checkDuplicateLoopEnd

		CMP al, byte [rdx]			; if two characters are identical, return error
		JE _errorEnd

		INC rdx						; else increment and check until end of base string

		JMP _checkDuplicateLoop

	_checkDuplicateLoopEnd:

	INC rcx				; baseLen++
	INC rbx				; baseStr++

	JMP _baseCheck

_atoiSetUp:
	CMP rcx,2	; check if baseLen is at least 2
	JL _errorEnd

	MOV rax,0	; Register A will contains the result of the atoi, initialized at 0
				; Register Destination Index contains the start of the numStr, as arg 1

_atoiLoop:
	CMP byte [rdi],0
	JE _end
	MOV rbx,0			; Register B will contain the index of the current num character in the base string
						; not using Register D cuz it gets wiped during multiplication operations

	_baseLoop:
		MOV r8b, byte [rsi + rbx]	; Register A contains the value at current base string

		CMP r8b,0		; check if baseString is over
		JE _errorEnd	; if so, current character is not in the base

		CMP byte [rdi],r8b
		JE _baseLoopEnd

		INC rbx			; Increment base string
		JMP _baseLoop

	_baseLoopEnd:
		MUL rcx			; multiply register A by the base length
		ADD rax, rbx	; add index in the base string as value to result
		INC rdi			; increment numStr
		JMP _atoiLoop

_end:
					; Register A contains the calculated result
	RET

_errorEnd:
	MOV rax,0		; Register A is set at 0 to return 0
	JMP _end

section .note.GNU-stack noalloc noexec nowrite progbits
