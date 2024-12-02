#include "../include/nameGenerator.h"

#define STR_BUFFER_SIZE  10
#define NAME_BUFFER_SIZE 50

void generateName(const LinkedList *srcLists,
                  LinkedList *dest, unsigned amountOfNames)
{
    char strBuffer[STR_BUFFER_SIZE];
    char nameBuffer[NAME_BUFFER_SIZE];

    //Go through every single syllable list and read one random syllable
    LinkedList currentList;
    getItem(srcLists, 0, currentList, sizeof(LinkedList*));

    /*
    getItem( &srcArray[0], getListSize(&srcArray[0]) - 1
            , strBuffer, sizeof(char)*STR_BUFFER_SIZE);
    addItem(&dest, strBuffer, sizeof(char)*stringLength(strBuffer));

    getItem( &srcArray[1], 1, strBuffer, sizeof(char)*STR_BUFFER_SIZE);
    addItem(&dest, strBuffer, sizeof(char)*stringLength(strBuffer));
    */
    return;
}
