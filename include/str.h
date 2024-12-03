#ifndef STR_H_INCLUDED
#define STR_H_INCLUDED

#include <stdlib.h>

/**
* This function concatenates the contents of two string pointers and returns the
* result on dest.
* The behaviour is undefined if dest is not large enough for the contents of
* both str1 and str2.
**/
void concatenateStrings(const char *src, char *dest);
/**
* Compares two given strings.
* It returns a negative value if str1 appears before str2 in lexografical order.
* It returns a zero if str1 are equal.
* It returns a positive value if str1 appears after str2 in lexografical order.
**/
int compareString(const char *str1, const char *str2);
/**
* Returns the length of a given string
**/
unsigned stringLength(const char *str);
void clearString(char *str, unsigned size);
char *createString(unsigned size);
void deleteString(char *str);
void removeCRLF(char *str);
void copyMemory(void *, const void*, size_t);

#endif // STR_H_INCLUDED
