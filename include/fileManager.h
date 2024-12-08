#ifndef FILEMANAGER_H_INCLUDED
#define FILEMANAGER_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

/**
* Reads a text file. For each line of the text file, it calls the given function
* passing the line itself and the given parameter as arguments.
* @param fileName - the path to the file
* @param func - pointer to the function to be called for each line. It must
 receive two void parameters
* @param param - the parameter that'll be passed to func together with the line
 read
* @return 0 if everything goes well, -1 otherwise
**/
int readTextFile(const char *fileName, void (*func)(void *, void *)
                 , void *param);
/**
* Opens a file in write mode and calls a given function with the file pointer as
 its first argument and param as its second argument.
* @param fileName - the path to the file
* @param func - pointer to the function to be called. It must receive a FILE
 pointer as its first argument, and a void * pointer as its second argument.
* @param param - the parameter that'll be passed to func
* @return 0 if everything goes well, -1 otherwise
**/
int writeTextFile(const char *fileName, void (*func)(FILE *, void *)
                  , void *param);
/**
* Appends data to a file.
* @param fileName - the path to the file
* @param data - the data to be appended to the file
* @param size - the size of the data
* @return 0 if everything goes well, -1 otherwise
**/
int appendTextFile(const char* fileName, void *data, unsigned size);

#endif // FILEMANAGER_H_INCLUDED
