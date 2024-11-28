#include "utils.h"

void copyMemory(void* dest,const void* src, size_t size)
{
    char *d = dest;
    const char *s = src;
    while(size--)
        *d++ = *s++;
}
