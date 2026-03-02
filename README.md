# libASM

Intel assembly language

## Registers

1972: **8-bit** 8008 Intel processor, with general registers labelled A, B, C, D and stack pointer

1978: **16-bit** 8086 (or "186") Intel processor with eXtended registers (AX, BX, CX, DX), subdivided into AH and AL for backward compatibility, added base, source and destination pointers register for string operations

**x86** or **80x86** architecture: family of Complex Instruction Set Computer (CISC) developped by Intel based on the 8086 chip and currently dominating in the desktop and laptop markets

1985: **32-bit** i386 (or "386") Intel processor, with Extended 64-bit registers (EAX, EBX, ECX, EDX) and backward compatibility

2003: **64-bit** Opteron AMD processor

**x64** architecture: Backward-compatible extension of x86, which extends x86's 8 general purpose registers to be 64-bit and adds 8 new ones named r5 to r15, all prefixed with R for register

For backward compatibility reasons, writing to EAX, EBX, ECX or EDX will zero out the rest of the register

### General purpose registers

#### RAX : **Accumulator**, for arithmetics

```
RAX : 0000 0000 0000 0000 0000 0000 0000 0000
					EAX : 0000 0000 0000 0000
								AX: 0000 0000
								AH: 0000
									 AL: 0000
```

#### RBX : **Base**, to access memory / offset

```
RBX : 0000 0000 0000 0000 0000 0000 0000 0000
					EBX : 0000 0000 0000 0000
								BX: 0000 0000
								BH: 0000
									 BL: 0000
```

#### RCX : **Counter**, for loops and shifts

```
RCX : 0000 0000 0000 0000 0000 0000 0000 0000
					ECX : 0000 0000 0000 0000
								CX: 0000 0000
								CH: 0000
									 CL: 0000
```

#### RDX : **Data**, for overflow, result of multiply and divide

```
RDX : 0000 0000 0000 0000 0000 0000 0000 0000
					EDX : 0000 0000 0000 0000
								DX: 0000 0000
								DH: 0000
									 DL: 0000
```

#### RSI : **Source Index**, for string operation

```
RSI : 0000 0000 0000 0000 0000 0000 0000 0000
					ESI : 0000 0000 0000 0000
								SI: 0000 0000
									SIL: 0000
```

#### RDI : **Destination Index**, for string operation

```
RDI : 0000 0000 0000 0000 0000 0000 0000 0000
					EDI : 0000 0000 0000 0000
								DI: 0000 0000
									DIL: 0000
```

#### RBP : **Base Pointer**

```
RBP : 0000 0000 0000 0000 0000 0000 0000 0000
					EBP : 0000 0000 0000 0000
								BP: 0000 0000
									BPL: 0000
```

#### RSP : **Stack pointer**

```
RSP : 0000 0000 0000 0000 0000 0000 0000 0000
					ESP : 0000 0000 0000 0000
								SP: 0000 0000
									SPL: 0000
```

#### R8, R9, R10, R11, R12, R13, R14, R15

```
R8 : 0000 0000 0000 0000 0000 0000 0000 0000
					R8D: 0000 0000 0000 0000
							  R8W: 0000 0000
								   R8B: 0000
```

## Calling convention

