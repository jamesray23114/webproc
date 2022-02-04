#pragma once

#include "../typedef.h"
#include "../mem/mem.h"

typedef struct cpu_s
{
    // these are not to be used by the user and are internal to the processor.
    byte intruction; // current instruction being ran.
    byte icount;     // current count within that instruction, used in multibyte instructions 
    byte power;      // current state of cpu (hlt? on? ect)

    uint64 rid;

    uint64 rip;
    uint64 resp;
    uint64 rsp;
    uint64 rsbp;

    uint64 ra;
    uint64 rb;
    uint64 rc;
    uint64 rd;

    uint64 r0;
    uint64 r1;
    uint64 r2;
    uint64 r3;
    uint64 r4;
    uint64 r5;
    uint64 r6;
    uint64 r7;

    uint64 rflags;
    uint64 rfeat;
    uint64 rcycles;
    uint64 rcontrol;

    // these are internal to the processor unlike the x86 arch
    memory* inttable;  // table of pointers to interrupt handlers
    memory* memtable;  // table of information regarding memory 
    memory* tasktable; // table of information regarding tasks
    memory* errstack;  // internal stack which error information is pushed onto,
    memory* local;     // memory local to this processor, may not be present
} cpu;



cpu* stdcpu_init()
{
    
}