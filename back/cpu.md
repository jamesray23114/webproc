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
| **rm8**  | 32 bit pointer to 8 bit value |
| **rm16** | 32 bit pointer to 16 bit value |
| **rm32** | 32 bit pointer to 32 bit value |
| **rm64** | 32 bit pointer to 64 bit value |
| **am8**  | 64 bit pointer to 8 bit value |
| **am16** | 64 bit pointer to 16 bit value |
| **am32** | 64 bit pointer to 32 bit value |
| **am64** | 64 bit pointer to 64 bit value |
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
| ADD 02h | these[^1] | adds to the first operand the second |
| SUB 03h | these[^1] | subtracts to the first operand the second |
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

[^1]:   **r16** -> **r16/32**, **r32** -> **r32/64**, **r64** -> **r64**, 
        **r16** -> **rm16/32**, **r32** -> **rm32/64**, **r64** -> **rm64**, 
        **rm16** -> **r16/32**, **rm32** -> **r32/64**, **rm64** -> **r64**, 
        **rm16** -> **rm16/32**, **rm32** -> **rm32/64**, **rm64** -> **rm64** 
        **r16** -> **i16/32**, **r32** -> **i32/64**, **r64** -> **i64**, 
        **rm16** -> **i16/32**, **rm32** -> **i32/64**, **rm64** -> **i64** 
    
    