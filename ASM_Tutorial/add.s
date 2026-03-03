section .data

section .text
global _start

_start:
		MOV al, 0b11111111	; can use 0b to indicate a binary value
		MOV bl, 0b0001
		ADD al, bl
		ADC ah,0			; ADC allow addition with carry
		INT 80h
