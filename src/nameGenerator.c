#include "../include/nameGenerator.h"

#define STR_BUFFER_SIZE  10
#define NAME_BUFFER_SIZE 50

void generateName(const LinkedList *srcLists,
                  LinkedList *dest, unsigned amountOfNames)
{
    char strBuffer[STR_BUFFER_SIZE];
    char nameBuffer[NAME_BUFFER_SIZE];
    srand(time(NULL));

    for(unsigned j = 0 ; j<amountOfNames ; j++)
    {
        clearString(nameBuffer, NAME_BUFFER_SIZE);
        //Go through every single list and read one random string
        for(unsigned i = 0 ; i<getListSize(srcLists) ; i++)
        {
            clearString(strBuffer, STR_BUFFER_SIZE);

            //Get a list
            LinkedList currentList;
            createList(&currentList);
            getItem(srcLists, i, &currentList, sizeof(LinkedList*));

            //Get random string
            unsigned randomNumber = (rand() % getListSize(&currentList));
            getItem(&currentList, randomNumber
                    , strBuffer, getItemSize(&currentList, j));

            concatenateStrings(strBuffer,nameBuffer);
        }

        printf("%s\n", nameBuffer);
    }
    return;
}
