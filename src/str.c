#include "../include/str.h"

void clearString(char *str, unsigned size)
{
    while(size--)
        *str++ = '\0';
}

void concatenateStrings(const char *src, char *dest )
{
    while(*dest)
        dest++;

    while(*src)
        *dest++ = *src++;
}

int compareString(const char *str1, const char *str2)
{
    while(*str1 && *str1 == *str2)
    {
        ++str1;
        ++str2;
    }

    return (int) (*str1 - *str2);
}

unsigned stringLength(const char *str)
{
    unsigned length = 0;

    while(*str++)
        length++;

    return length;
}

char *createString(unsigned size)
{
    char *newString;
    if( (newString = (char *)malloc(sizeof(char)*size)) == NULL )
    {
        free(newString);
        return NULL;
    }

    return newString;
}

void deleteString(char *str)
{
    free(str);
}

void removeCRLF(char *str){
    while(*str)
        str++;

    while(*--str == '\r' || *str == '\n')
        *str = '\0';
}

void copyMemory(void* dest,const void* src, size_t size)
{
    char *d = dest;
    const char *s = src;
    while(size--)
        *d++ = *s++;
}
