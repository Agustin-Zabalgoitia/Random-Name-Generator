#include "../include/str.h"

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

void clearString(char *str, unsigned number)
{
    while(number--)
        *str++ = '\0';
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

void removeCRLF(char *str)
{
    while(*str)
        str++;

    while(*--str == '\r' || *str == '\n')
        *str = '\0';
}

void replaceNullWithCR(char *str)
{
    while(*str)
        str++;

    *str = '\r';
}

void copyMemory(void* dest,const void* src, size_t size)
{
    char *d = dest;
    const char *s = src;
    while(size--)
        *d++ = *s++;
}

int charToInteger(const char ch)
{
    return ch - 48;
}

int stringToInteger(const char *str)
{
    const char *init = str;
    while(*str)
        str++;

    int number = charToInteger(*(--str));

    for(int i = 10 ; init != str-- ; i*=10)
        number += (charToInteger(*(str))*i);

    return number;
}
