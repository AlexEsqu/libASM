extern printf ; telling nasm these function will be linked later
extern exit


section .data
		msg DD "Hello World!",0
		msg2 DD "This is a test!",0
		fmt DB "Output is: %s %s",10,0 ; 10 is newline '\n'
section .text

global main ; function named 'main' necessary if running object file through gcc


main:
		PUSH msg2 ; ordering opposite to how called in C
		PUSH msg ; so printf(format, msg, msg2)
		PUSH fmt ; push msg2, msg, format
		CALL printf
		PUSH 10
		CALL exit
