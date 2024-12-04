#include "../include/utils.h"

void loadTextToList(void *text, void *list)
{
    //Make sure to not include the \n character
    removeCRLF(text);
    unsigned length = stringLength((const char*)text)+1;
    char *newText = createString(length);
    clearString(newText, length);
    copyMemory(newText, text, sizeof(char)*length);

    addItem((LinkedList *) list, text, sizeof(char)*length);
    deleteString(newText);
}

void loadTextFileToList(const  char *filename, LinkedList *list)
{
    readTextFile(filename, loadTextToList, list);
}

void writeTextFromList(FILE *fp, void *l)
{
    LinkedList *list = (LinkedList *) l;
    unsigned listSize = getListSize(list);

    for(unsigned i = 0 ; i<listSize ; i++)
    {
        unsigned strSize = getItemSize(list, i);
        char *auxStr = createString(strSize);
        getItem(list, i, auxStr, strSize);
        replaceNullWithCR(auxStr);

        fwrite(auxStr, strSize, 1, fp);

        deleteString(auxStr);
    }
}

void writeListToTextFile(const char *filename, LinkedList *list)
{
    writeTextFile(filename, writeTextFromList, list);
}
