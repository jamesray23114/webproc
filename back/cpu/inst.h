#pragma once

typedef enum opcode_e
{
    // these define the first byte of an instruction, many of these will require extra bytes to encode fully
    NOP = 0,  
    HLT,
    
    ADD,
    SUB, 
    ADC,
    SBC,
    
    AND,
    LOR,
    XOR,
    
    INC,
    DEC,
    
    BSL,
    BSR,
    ROL,
    ROR,
    
    MOV,
    
    PUSH,
    POP,
    
    CALL,
    JUMP,
    INT,
    RET,
    IRET,
    
    MUL,
    DIV,
    
    CMP,
    BIT,

    JZ, JNZ,
    JC, JNC,
    JO, JNO,
    JB, JA,
    JN, JNN,

} opcode;