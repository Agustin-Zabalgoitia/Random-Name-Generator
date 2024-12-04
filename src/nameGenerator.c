#include "../include/nameGenerator.h"

#define NAME_BUFFER_SIZE 255

void generateName(const LinkedList *srcLists,
                  LinkedList *dest, unsigned amountOfNames)
{
    char nameBuffer[NAME_BUFFER_SIZE];
    char *strBuffer;
    srand(time(NULL));

    for(unsigned j = 0 ; j<amountOfNames ; j++)
    {
        clearString(nameBuffer, NAME_BUFFER_SIZE);
        //Go through every single list and read one random string
        for(unsigned i = 0 ; i<getListSize(srcLists) ; i++)
        {
            //Get a list
            LinkedList currentList;
            createList(&currentList);
            getItem(srcLists, i, &currentList, sizeof(LinkedList*));

            //Get random string
            unsigned randomNumber = (rand() % getListSize(&currentList));
            unsigned strLength = getItemSize(&currentList, randomNumber);

            strBuffer = createString(strLength);
            clearString(strBuffer, strLength);
            getItem(&currentList, randomNumber
                    , strBuffer, strLength);

            concatenateStrings(strBuffer,nameBuffer);
        }
        printf("%s\n",nameBuffer);

        addItem(dest, nameBuffer, stringLength(nameBuffer)+1);
        deleteString(strBuffer);
    }
    return;
}
