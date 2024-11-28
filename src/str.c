#include "../include/str.h"

void concatenateStrings(const char *str1, const char *str2, char *dest )
{
    while(*str1)
        *dest++ = *str1++;

    while(*str2)
        *dest++ = *str2++;
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
