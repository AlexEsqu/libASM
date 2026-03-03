section .text
global _start

_start:
		MOV eax,11
		MOV ecx,2
		DIV ecx ; 1st operand and result in EAX, remainder in EDX
		INT 80h
