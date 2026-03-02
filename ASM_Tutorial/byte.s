section	.data
		num DB 1
		num2 DB 2

section	.text
global	_start

_start:
		MOV eax, 1
		MOV ch, [num]
		MOV cl, [num2]
		INT 80h

