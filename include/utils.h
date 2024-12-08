#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <stdlib.h>
#include "errorNumbers.h"
#include "str.h"
#include "list.h"
#include "fileManager.h"

/**
* Given a path to a text file, it loads the contents of the text file into the
given list
* @param path - string containing the file path
* @param list - pointer to the list were the contents of the file will be stored
**/
void loadTextFileToList(const  char *path, LinkedList *list);
/**
* Given a path to a file, it writes the content of the list into a new text file
 or overwrites any file with the same name.
* @param filename - string containing the file path
* @param list - pointer to the list
**/
void writeListToTextFile(const char *filename, LinkedList *list);
/**
* Processes command-line arguments passed as argv to identify a matching option
 from a provided array of valid options.
* The arguments passed as argv must start with a '-' for short options (only
 one character) or with '--' for long options.
* Any argument that doesn't start with '-' or '--' will return a 0.
* Any argument that starts with '-' or '--' but is not present in the options
 array will return a ?.
* Any argument that starts with '-' and is equal to the first character of one
 of the strings present in the options array will return that character.
* Any argument that starts with '--' and is equal to a string present in the
 options array will return its first character.
* The options themselves should not contain a '-' or '--' at the beginning.
* @param argv - an array of strings where the arguments are stored, usually argv
 in main
* @param options - an array of strings that contains the valid options
* @return '0' if the argument doesn't start with '-' or '--', '?' if the
 argument starts with '-' or '--' but is not present in the options array, and
 the first character of the matching option
**/
int getOptions(char **argv, const char *options[]);

#endif // UTILS_H_INCLUDED
