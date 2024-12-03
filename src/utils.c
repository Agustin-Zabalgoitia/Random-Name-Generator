#include "../include/utils.h"

void loadTextToList(void *text, void *list)
{
    //Make sure to not include the \n character
    removeCRLF(text);
    unsigned length = stringLength((const char*)text)+1;
    char *newText = createString(length);
    clearString(newText, length);
    copyMemory(newText, text, length);

    addItem((LinkedList *) list, text, sizeof(char)*length);
}

void loadTextFileToList(const  char *filename, LinkedList *list)
{
    readTextFile(filename, loadTextToList, list);
}
