#include "../include/nameGenerator.h"

#define NAME_BUFFER_SIZE 255

void generateName(const LinkedList *srcLists,
                  LinkedList *dest, unsigned amountOfNames,
                  char randomizeLists, char printNames)
{
    char nameBuffer[NAME_BUFFER_SIZE];
    char *strBuffer;
    srand(time(NULL));

    for(unsigned j = 0 ; j<amountOfNames ; j++)
    {
        clearString(nameBuffer, NAME_BUFFER_SIZE);
        //Go through every single list and read one random string
        unsigned lastList = randomizeLists ? rand() % getListSize(srcLists)
                            : getListSize(srcLists);
        for(unsigned i = 0 ; i<lastList ; i++)
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

        if(printNames)
            printf("%s\n",nameBuffer);

        addItem(dest, nameBuffer, stringLength(nameBuffer)+1);
        deleteString(strBuffer);
    }
    return;
}
