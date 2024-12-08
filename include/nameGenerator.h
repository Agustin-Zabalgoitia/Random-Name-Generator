#ifndef NAMEGENERATOR_H_INCLUDED
#define NAMEGENERATOR_H_INCLUDED

#include "list.h"
#include "str.h"
#include <stdio.h>
#include <time.h>

/**
* Generate names based on lists containing strings.
* @param srcLists - pointer to a list containing lists that contains the
 strings used to generate names
* @param dest - pointer to a linked list to store the names
* @param amountOfNames - amount of names to generate
* @param randomizeLists - if different than 0, then it'll use a random number of
 lists of strings to generate names
* @param printNames - if different than 0, then it'll print the generated names
 on screen
**/
void generateName(const LinkedList *srcLists,
                  LinkedList *dest, unsigned amountOfNames,
                  char randomizeLists, char printNames);

#endif // NAMEGENERATOR_H_INCLUDED
