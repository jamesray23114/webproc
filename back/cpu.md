| OPCODE | OPERANDS | DESC |
| ------ | -------- | ---- |
| ***STATE*** | --- | --- |
| NOP 00h | static [^1] 0x1, 0x10, 0x44 | performs no operation if it reads the correct order of bytes, otherwise triggers invalid intruction | 
| HLT 01h | N/A | halts the processor untill a interupt is triggered | 
| ***MATH*** | --- | --- |
| ADD 02h | any [^2] | adds to the first operand the value in the second
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

[^1]: any static values must match those lister, else an esxception is thrown
[^2]: r/r r/m m/r m/m r/i m/i