section .text
global _start

_start:
		MOV eax,2
		SHR eax,1 ; 0010 -> 0001 0 at end will go to carry flag
		INT 80h
