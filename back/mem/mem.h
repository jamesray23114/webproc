#pragma once

#include <stdlib.h>
#include <ctype.h>
#include "../typedef.h"
// TYPEDEFS

typedef struct mflags_s
{
    byte av : 1; // memory can be used 
    byte lc : 1; // memory is local to processor 
    byte rd : 1; // memory can be read
    byte wr : 1; // memory can be written
} mflags;

typedef struct memory_s
{
    mflags flags;
    uintn len;
    uintn base;
    byte* data;
} memory;

#define SUCCESS 0
#define NOTAVALIABLE 1
#define NOTWRITABLE  2
#define NOTREADABLE  3
#define ACCESSABOVE  4
#define ACCESSBELOW  5

memory* mem_init(uintn maxsize, uintn base, mflags flags)
{
    memory* mptr =(memory*) malloc(sizeof(memory));
    mptr->flags = flags;
    mptr->len = maxsize;
    mptr->base = base;
    mptr->data = (byte*) malloc(maxsize);
    memset(mptr->data, 0, maxsize);
    return mptr;
}

char ipc(char data)
{
    if(isprint(data)) return data; else return '.';
}

void mem_print(memory* mem)
{
    printf("memory from %x to %x\n", mem->base, mem->base + mem->len);
    for(int i = 0; i < mem->len; i += 16)
        printf("\t%4.4X->%4.4X: %3.3hhu %3.3hhu %3.3hhu %3.3hhu %3.3hhu %3.3hhu %3.3hhu %3.3hhu : %3.3hhu %3.3hhu %3.3hhu %3.3hhu %3.3hhu %3.3hhu %3.3hhu %3.3hhu |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",
            i, i+16,
            mem->data[i + 0], mem->data[i + 1], mem->data[i + 2], mem->data[i + 3], 
            mem->data[i + 4], mem->data[i + 5], mem->data[i + 6], mem->data[i + 7],
            mem->data[i + 8], mem->data[i + 9], mem->data[i + 10], mem->data[i + 11], 
            mem->data[i + 12], mem->data[i + 13], mem->data[i + 14], mem->data[i + 15],
            ipc(mem->data[i + 0]), ipc(mem->data[i + 1]), ipc(mem->data[i + 2]), ipc(mem->data[i + 3]), 
            ipc(mem->data[i + 4]), ipc(mem->data[i + 5]), ipc(mem->data[i + 6]), ipc(mem->data[i + 7]),
            ipc(mem->data[i + 8]), ipc(mem->data[i + 9]), ipc(mem->data[i + 10]), ipc(mem->data[i + 11]), 
            ipc(mem->data[i + 12]), ipc(mem->data[i + 13]), ipc(mem->data[i + 14]), ipc(mem->data[i + 15])
        );
    printf("\n\n");
}

#define MEMWRITE(type, name) static inline byte mem_write##name(memory* mem, uintn offset, type data) \
{                                                                           \
    if(!mem->flags.av) return NOTAVALIABLE;                                 \
    if(!mem->flags.wr) return NOTWRITABLE;                                  \
    if(offset > mem->len + mem->base - sizeof(type)) return ACCESSABOVE;    \
    if(offset < mem->base) return ACCESSBELOW;                              \
    *((type*)(mem->data - mem->base + offset)) = data;                      \
    return SUCCESS;                                                         \
}  
#define MEMREAD(type, name) static inline byte mem_read##name(memory* mem, uintn offset, type* data) \
{                                                                           \
    if(!mem->flags.av) return NOTAVALIABLE;                                 \
    if(!mem->flags.wr) return NOTREADABLE;                                  \
    if(offset > mem->len + mem->base - sizeof(type)) return ACCESSABOVE;    \
    if(offset < mem->base) return ACCESSBELOW;                              \
    *data = *((type*)(mem->data - mem->base + offset));                     \
    return SUCCESS;                                                         \
}

MEMWRITE(byte, b);
MEMWRITE(uint16, w);
MEMWRITE(uint32, d);
MEMWRITE(uint64, q);

MEMREAD(byte, b);
MEMREAD(uint16, w);
MEMREAD(uint32, d);
MEMREAD(uint64, q);
