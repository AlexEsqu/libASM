# libASM


## What is a computer?

```
	____data bus___________________________________
 ___|__			 ___|____		 ___|___________
/		\		/		 \		/				\
|  CPU 	|		| Memory |		| I/O devices	|
\_______/		\________/		\_______________/
  |  |	control	   | |				|	|
  |  |____bus______|_|______________|___|_____________
  |				   |				|
  |__address_bus___|________________|_____________

```

### Bus
Communication between pieces of hardware
- **Control Bus**:
Synchronize action between all devices, where reading / writing
- **Address Bus**:
Holds address of instruction in data, where working
- **Data Bus**:
Handle transfer of data between CPU, I/O, Memory...

### CPU
- **High Frequency Clock**:
Ticks at constant rate between on and off to synchronize CPU and bus, every tick does one operation, measured in oscillations per second (1 GHz = 1 billion times / second)
- **Arithmetic Logic Unit**:
Special part of CPU which does all computation sur as ADD, OR, AND, etc.
- **Memory Registers**:
Very fast memory storage on the CPU itself
- **Control Unit**:
Decode instruction to direct operation to other unit (I/O, Memory...)

### Instruction Execution Cycle
Predefined steps to execute instruction, known as **fetch decode execute**
1. fetch instruction from instruction queue
2. decode instruction and check for operand
3. if operand, fetch from memory / registers
4. execute instruction and update status flags
5. store result if needed

### Memory

Reading from memory is slow, ~ 4 clock cycle
1. place address of value to read on address bus
2. assert (change processor RD pin)
3. wait one clock cycle for memory response
4. copy data from data bus to destination

Reading from register is very fast, ~ 1 clock cycle

#### Cache
Memory wth static RAM used to reduce time to access some memory
- Level 1 cache stored on CPU
- Level 2 stored outside accessed by high-speed data bs

### Processor Modes

- Protected Mode: native processor state, can access eveyr feature so long as does not modify other process memory
- Real Address Mode : can access all parts of component / hardware devices
- System Management Mode : design a system for a chip specifically

## Registers

### History

1972: **8-bit** 8008 Intel processor, with general registers labelled A, B, C, D and stack pointer

1978: **16-bit** 8086 (or "186") Intel processor with eXtended registers (AX, BX, CX, DX), subdivided into AH and AL for backward compatibility, added base, source and destination pointers register for string operations

**x86** or **80x86** architecture: family of Complex Instruction Set Computer (CISC) developped by Intel based on the 8086 chip and currently dominating in the desktop and laptop markets

1985: **32-bit** i386 (or "386") Intel processor, with Extended 64-bit registers (EAX, EBX, ECX, EDX) and backward compatibility

2003: **64-bit** Opteron AMD processor

**x64** architecture: Backward-compatible extension of x86, which extends x86's 8 general purpose registers to be 64-bit and adds 8 new ones named r5 to r15, all prefixed with R for register

For backward compatibility reasons, writing to EAX, EBX, ECX or EDX will zero out the rest of the register (ie the smaller declination such as AX, AH, AL for EAX)



### General Purpose Registers

#### 1. RAX : **Accumulator**

Automatically used for multiplication and division and return values

```
RAX : 0000 0000 0000 0000 0000 0000 0000 0000
					EAX : 0000 0000 0000 0000
								AX: 0000 0000
								AH: 0000
									 AL: 0000
```

#### 2. RBX : **Base**, to access memory / offset

```
RBX : 0000 0000 0000 0000 0000 0000 0000 0000
					EBX : 0000 0000 0000 0000
								BX: 0000 0000
								BH: 0000
									 BL: 0000
```

#### 3. RCX : **Counter**, for loops and shifts

Used as loop counter by CPU

```
RCX : 0000 0000 0000 0000 0000 0000 0000 0000
					ECX : 0000 0000 0000 0000
								CX: 0000 0000
								CH: 0000
									 CL: 0000
```

#### 4. RDX : **Data**

```
RDX : 0000 0000 0000 0000 0000 0000 0000 0000
					EDX : 0000 0000 0000 0000
								DX: 0000 0000
								DH: 0000
									 DL: 0000
```

#### 5. RSI : **Source Index**

```
RSI : 0000 0000 0000 0000 0000 0000 0000 0000
					ESI : 0000 0000 0000 0000
								SI: 0000 0000
									SIL: 0000
```

#### 6. RDI : **Destination Index**

```
RDI : 0000 0000 0000 0000 0000 0000 0000 0000
					EDI : 0000 0000 0000 0000
								DI: 0000 0000
									DIL: 0000
```

#### 7. RBP : **Base Pointer**

Reference function parameters and local variables on the stack

```
RBP : 0000 0000 0000 0000 0000 0000 0000 0000
					EBP : 0000 0000 0000 0000
								BP: 0000 0000
									BPL: 0000
```

#### 8. RSP : **Stack pointer**

Points to current stack address

```
RSP : 0000 0000 0000 0000 0000 0000 0000 0000
					ESP : 0000 0000 0000 0000
								SP: 0000 0000
									SPL: 0000
```

#### 9 - R8, R9, R10, R11, R12, R13, R14, R15

```
R8 : 0000 0000 0000 0000 0000 0000 0000 0000
					R8D: 0000 0000 0000 0000
							  R8W: 0000 0000
								   R8B: 0000
```

### Special Purpose Registers

#### EIP
Instruction pointer, pointing to address of next instruction

#### EFLAGS
Flags denoting status of an operation
- CF (carry flag)
- OF (overflow flag)
- SF (sign flag)
- ZF (zero flag)
- AC (auxilliary flag)

##### Carry flag (CF)
represent a carry and borrow in substraction

##### Auxilliary flag


##### Signed Flag (SF)
Set to 1 when operation produced a negative output

##### Parity flag (PF)
set to 1 when result is odd, to 0 if even

Can help identify problem in transmitting data

##### Interrupt Flag (IF)
set to 1 when interrupt allowed

Generally set at beginning of execution of the program

##### Floating Point Registers (XMM0 - XMM15)


## ASM Syntax

NASM : x86 syntax based on Intel, more approachable than AT&T syntax

Need to export an entry point to the program (`global _start`)

To end program, `INT` interrupt, with `80h` calls exit syscall

### To assemble into object file using NASM:
`nasm -f elf -o objectFileName.o sourceFile.s`

### To bind / link into binary targetting a specific architecture:
`ld -m elf_i386 -o binaryName objectFile.o`

### To run in GDB:
- `gdb <binary>`
- `layout asm`
- `run`
- `stepi` to step to next line
- `info registers <register name>` to examine register content
- `x/x <memory address>` to examine content of a memory address
- `p $<register>.<type>[0]` such as `p $xmm1.v4_float[0]`

`echo "set disassembly-flavor intel" > ~/.gdbinit` to have intel style layout

### To create variables:
in `section .data`, set a name, size in bytes, and value, such as
``` ASM
section .data
	num DD 5
```
Can separate values in a list with a `,` such as `list DB 1,3,5,6`

For string, add null-terminator such as `str DB "ABA",0`

### To use variables:
access varName address with `varName`, or value with `[varName]`


## Arithmetic

### Addition
`ADD`

### Subtraction
`SUB`

### Multiplication
`MUL`: Will always use A register for result

Will expand the register if the result is bigger than the register declination can use

`IMUL` will assume all operands are signed

### Division
`DIV`: Will always use A register for result

Will put remained in EDX

`IDIV` will assume all operands are signed

### Logical Operators
- `AND`: 1 if both are 1, else 0
- `OR`: 1 if any is 1, else 0
- `XOR`: 1 if only one 1, else 0
- `NOT`: flip bits

### Mask
**Mask**: `AND` with a value, where values not set to any particular values are cleared such as `AND eax,0xF`

### Shift
`SHR`: shift value one bit to the right (ie divide by 2)

`SHL`: shift value one bit to the left (ie multiply by 2)

`SAR`: arithmetic shift to the right, preserve the sign bit

`SAL`: arithmetic shift to the left, preserve the sign bit

### Jump
`JMP`: always jumps

`JL`: jump low, if lesser than in last comparison

`JLE`: jump equal or lower than

`JG`: jump great, if greater than in last comparison

`JGE`: jump equal or greater than

`JE`: jump if equal

`JNE`: jump if not equal

`JZ`: jump if zero, similar to `JE` since comparison is 0 if equal

`JNZ`: jump if not zero

### Floating Point

`MOVSS`: move instruction scalar single precision

`ADDSS`: add instruction scalar single precision

#### Single Precision
32-bit floating point number

#### Scalar
Moving a single decimal value; because register could hold packed data, multiple value moved at the same time

#### Comparison for floating points

`UCOMISS`: comparison with floating point

#### Jumps for floating points

`JB`: jump below, same as less than

`JBE`: jumpe below equal

`JAE`: jump above equal

`JA`: jump above

still use `JE` for jump if equal

## Calling functions

`PUSH` argument on the stack on the order expected by function

`CALL` function defined as extern

Beware, other functions will make use of volatile registers, so store any important data in non volatile ones

**Position Independant Executable**:

`nasm -f elf -o objectfilename.o sourcefile.s`

`gcc -no-pie -m32 objectfile.o <potential C file> -o binaryname`

## Calling Syscall

Syscalls are made by setting the required registers to specific values to pick the syscall, and set its arguments, such as:

| %rax | System call | %rdi | %rsi | %rdx | %r10 | %r8 | %r9 |
|------|-------------|------|------|------|------|-----|-----|
| 0 | sys_read | unsigned int fd | char *buf | size_t count | | | |
| 1 | sys_write | unsigned int fd | const char *buf | size_t count | | | |
| 2 | sys_open | const char *filename | int flags | int mode | | | |
| 3 | sys_close | unsigned int fd | | | | | |
| 4 | sys_stat | const char *filename | struct stat *statbuf | | | | |
| 5 | sys_fstat | unsigned int fd | struct stat *statbuf | | | | |
| 6 | sys_lstat | const char *filename | struct stat *statbuf | | | | |
| 7 | sys_poll | struct poll_fd *ufds | unsigned int nfds | long timeout_msecs | | | |
| 8 | sys_lseek | unsigned int fd | off_t offset | unsigned int origin | | | |
| 9 | sys_mmap | unsigned long addr | unsigned long len | unsigned long prot | unsigned long flags | unsigned long fd | unsigned long off |

## Errno

`extern __errno_location`

`CALL __errno_location wrt ..plt`
