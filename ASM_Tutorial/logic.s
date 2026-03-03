section .text
global _start

_start:
		MOV eax,0b1010
		MOV ebx,0b1100
		AND eax,ebx ; any 0 will result in 0, otherwise 1
		; result: 1000 or 8

		MOV eax,0b1010
		MOV ebx,0b1100
		OR eax,ebx ; any 1 will result in 1, otherwise 0
		; result: 1110 or 14

		MOV eax,0b1010
		MOV ebx,0b1100
		XOR eax,ebx ; single 1 will result in 1, otherwise 0
		; result: 0110 or 6

		MOV eax,0b1010
		NOT eax ; flip all bits to their opposites (1 to 0, 0 to 1)
		; result: 0101
		; but signed as negative so -11

		AND eax,0xF ; removing all the flipped bits not needed by our operation

		MOV al,0b1010
		NOT al			; still result in absurdly high number

		INT 80h
