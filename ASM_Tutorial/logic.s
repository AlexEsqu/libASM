section .text
global _start

_start:
		MOV eax,0b1010
		MOV ebx,0b1100
		AND eax,ebx ; anywhere with 0 will result in 0, otherwise 1

		MOV eax,0b1010
		MOV ebx,0b1100
		OR eax,ebx ; anywhere with 1 will result in 1, otherwise 0

		MOV eax,0b1010
		MOV ebx,0b1100
		NOT eax ; flip all bits to their opposites (1 to 0, 0 to 1)
		INT 80h
