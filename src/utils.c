#include "../include/utils.h"

void loadTextToList(void *text, void *list)
{
    unsigned length = stringLength((const char*)text);
    addItem((LinkedList *) list, text, sizeof(char)*length);
}

void loadTextFileToList(const  char *filename, LinkedList *list)
{
    readTextFile(filename, loadTextToList, list);
}
