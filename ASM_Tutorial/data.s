section	.data
		num DD 5 ; set the size of the data, here double word / 4 bytes so same size as register, and value stored

section	.text
global	_start

_start:
		MOV eax, 1
		MOV ebx, [num] ; num is the address of the data, [num] is the value at the data
		INT 80h

