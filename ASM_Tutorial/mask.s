section .text
global _start

_start:
		MOV eax0b1010
		NOT eax ; flipping the 10 will result in negative value
		AND eax,0x0000000F ; require anding the sign part of the num
		AND eax,0xF ; technically 0 are superfluous

		INT 80h
