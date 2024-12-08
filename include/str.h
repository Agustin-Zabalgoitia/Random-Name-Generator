#ifndef STR_H_INCLUDED
#define STR_H_INCLUDED

#include <stdlib.h>

/**
* This functions concatenates the contents of dest to src.
* It assumes dest has enough space to store both, its own content, and src's
content.
* @param src - pointer to the string to copy from
* @param dest - pointer to the string to append to
**/
void concatenateStrings(const char *src, char *dest);
/**
* Compares two given strings.
* It returns a negative value if str1 appears before str2 in lexografical order.
* It returns a zero if str1 are equal.
* It returns a positive value if str1 appears after str2 in lexografical order.
* @param str1 - pointer to a string that'll be compared with str2
* @param str2 - pointer to a string that'll be compared with str1
* @return Result of the comparison between str1 and str2
**/
int compareString(const char *str1, const char *str2);
/**
* Returns the length of a given string, counting all the characters in it, until
 it reaches the first null character.
* @param str - pointer to the given string
* @return Lenght of the given string
**/
unsigned stringLength(const char *str);
/**
* Fills the given string with the 'number' of null characters
* @param str - pointer to the string to be cleared
* @param number - amount of null characters that'll be copied to str
**/
void clearString(char *str, unsigned number);
/**
* Allcates memory to be used as a string and returns a pointer to the beginning
of said memory.
* @param size - size of the memory to be used for the string
* @return Pointer to the beginning of the newly allocated memory
**/
char *createString(unsigned size);
/**
* Frees memory allocated to a string
* @param str - pointer to the string to be deleted
**/
void deleteString(char *str);
/**
* Removes any carriage return or linefeed from the end of the given string.
* @param str - pointer to the string to be modified
**/
void removeCRLF(char *str);
/**
* Replaces the null character at the end of the given string for a carriage
 return
 @param str - pointer to the string to be modified
**/
void replaceNullWithCR(char *str);
/**
* Copies 'size' characters from src to dest.
* This functions assumes dest has enough space to store the contents of src
* @param dest - pointer to the object to copy to
* @param src - pointer to the objecto to copy from
* @param size - the number of characters to copy
**/
void copyMemory(void * dest, const void* src, size_t size);
/**
* Converts a char to the numerical value it's representing.
* @param ch - the character to be converted
* @return The number that ch is representing
**/
int charToInteger(const char ch);
/**
* Converts a string into an integer. It assumes the given string represents a
 valid positive integer.
* @param str - pointer to the string to be converted to an int
* @return The int that str represents
**/
int stringToInteger(const char *str);

#endif // STR_H_INCLUDED
