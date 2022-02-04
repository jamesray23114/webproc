>## OPERAND TYPES
---
| OPERAND | DESC |
| ------- | ---- |
| N/A | opcode is encoded as a single byte |
| static | opcode needs a specific order of bytes, else a invalid instruction exception happens |
| **r8** | register to 8 bit value |
| **r16** | register to 16 bit value |
| **r32** | register to 32 bit value |
| **r64** | register to 64 bit value |
| **32m8**  | 32 bit pointer to 8 bit value |
| **32m16** | 32 bit pointer to 16 bit value |
| **32m32** | 32 bit pointer to 32 bit value |
| **32m64** | 32 bit pointer to 64 bit value |
| **m8**  |  64 bit pointer to 8 bit value |
| **m16** | 64 bit pointer to 16 bit value |
| **m32** | 64 bit pointer to 32 bit value |
| **m64** | 64 bit pointer to 64 bit value |
| **i8**  |  8 bit immediate value |
| **i16** | 16 bit immediate value |
| **i32** | 32 bit immediate value |
| **i64** | 64 bit immediate value |

>## OPERAND ENCODINGS
---

>## OPCODES
---
| OPCODE | OPERANDS | DESC |
| ------ | -------- | ---- |
| ***STATE*** | --- | --- |
| NOP 00h | static 0x1, 0x10, 0x44 | performs no operation | 
| HLT 01h | N/A | halts the processor untill a interupt is triggered | 
| ***MATH*** | --- | --- |
| ADD 02h | these[^1] | adds to the first operand the value in the second |
SUB 
ADC
SBC

AND
LOR
XOR

INC
DEC

BSL
BSR
ROL
ROR

MOV

PUSH
POP

CALL
JUMP
INT
RET
IRET

MUL
DIV

CMP
BIT

JZ JNZ
JC JNC
JO JNO
JB JA
JN JNN

[^1]:  
**r16**->**r16**,  **r16**->**r32**,  **r16**->**r64**, 
**r32**->**r32**,  **r32**->**r64**,  **r64**->**r64**,
**32m16**->**r16**,  **32m16**->**r32**,  **32m16**->**r64**, 
**32m32**->**r32**,  **32m32**->**r64**,  **32m64**->**r64**,