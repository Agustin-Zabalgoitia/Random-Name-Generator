#ifndef STR_H_INCLUDED
#define STR_H_INCLUDED

/**
* This function concatenates the contents of two string pointers and returns the
* result on dest.
* The behaviour is undefined if dest is not large enough for the contents of
* both str1 and str2.
**/
void concatenateStrings(const char *str1, const char *str2, char *dest);
/**
* Compares two given strings.
* It returns a negative value if str1 appears before str2 in lexografical order.
* It returns a zero if str1 are equal.
* It returns a positive value if str1 appears after str2 in lexografical order.
**/
int compareString(const char *str1, const char *str2);

#endif // STR_H_INCLUDED
