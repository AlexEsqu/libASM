section .text
global _start

_start:
		MOV al,0xFF ; will expand result into ax if overflow
		MOV bl,0x2
		MUL bl ; doesn't require two operands, only the one not stored in A register
		; IMUL bl ; assume signed operands
		INT 80h
