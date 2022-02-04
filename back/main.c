#include "webio/open.h"
#include "mem/mem.h"

#define TESTM(mem, loc, ch) error = mem_writeb(mem, loc, ch); if(error) printf("error %hhu at %c\n", error, ch);

int main(void)
{
    memory* ram = mem_init(128, 128, (mflags){.rd = 1, .wr = 1, .av = 1});

    int error = 0;

    mem_print(ram);
} 