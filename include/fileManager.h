#ifndef FILEMANAGER_H_INCLUDED
#define FILEMANAGER_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

/**
* Reads a text file. For each line of the text file, it calls the given function
* passing it as an argument the line itself.
**/
int readTextFile(char *, void (*)(void *));

#endif // FILEMANAGER_H_INCLUDED
