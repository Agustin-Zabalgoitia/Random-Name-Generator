#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <stdlib.h>
#include "errorNumbers.h"
#include "str.h"
#include "list.h"
#include "fileManager.h"

/**
* Given a path, loads a text file to a given list
**/
void loadTextFileToList(const  char *path, LinkedList *list);
void writeListToTextFile(const char *filename, LinkedList *list);

#endif // UTILS_H_INCLUDED
