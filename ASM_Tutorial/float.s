section .data
		x DD 3.14
		y DD 2.1
section .text
global _start
_start:
		MOVSS xmm0,[x] ; scalar single precision (32bit floating point numbers)
		MOVSS xmm1,[y] ; use special floating point register
		ADDSS xmm0,xmm1 ; all instruction similar with SS and floating point registers
		MOV ebx,1
		INT 80h

