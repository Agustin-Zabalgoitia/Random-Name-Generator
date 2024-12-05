#include <stdio.h>
#include <stdlib.h>

#include "../include/fileManager.h"
#include "../include/str.h"
#include "../include/binaryTree.h"
#include "../include/list.h"
#include "../include/utils.h"
#include "../include/nameGenerator.h"

void showString(void *str, void* nothing)
{
    printf("%s", (char*) str);
}

int main(int argc, char *argv[])
{
    //Save text from each file in a different list
    LinkedList *listFromFile = (LinkedList *)malloc(
                                                sizeof(LinkedList)*(argc-1));
    LinkedList *aux = listFromFile;
    while(*++argv != NULL)
    {
        createList(listFromFile);
        loadTextFileToList(*argv, listFromFile);
        listFromFile++;
    }
    listFromFile = aux;

    //Store the lists previously created in a list of lists
    LinkedList srcLists;
    createList(&srcLists);
    while(--argc>0)
        addItem(&srcLists, listFromFile++, sizeof(LinkedList*));

    //Generate names and store them in dest
    LinkedList dest;
    createList(&dest);
    generateName(&srcLists, &dest, 100);

    //Testing output file
    writeListToTextFile("names.txt", &dest);

    return 0;
}
