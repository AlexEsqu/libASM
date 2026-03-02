section .data
section .text
global	_start

_start:
	MOV eax, 1 ; set which instruction when interrupt 80 is called (here exit syscall)
	MOV ebx, 10 ; set exit status code used by exit syscall
	INT 80h ; interrupt
