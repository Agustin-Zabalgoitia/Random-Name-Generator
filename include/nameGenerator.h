#ifndef NAMEGENERATOR_H_INCLUDED
#define NAMEGENERATOR_H_INCLUDED

#include "list.h"
#include "str.h"
#include <stdio.h>
#include <time.h>

/**
* @param srcLists: a list containing lists that contains the strings used to
generate names
* @param dest: pointer to a linked list to store the names
* @param amountOfNames: amount of names to generate and store on dest
**/
void generateName(const LinkedList *srcLists,
                  LinkedList *dest, unsigned amountOfNames,
                  char randomizeLists, char printNames);

#endif // NAMEGENERATOR_H_INCLUDED
