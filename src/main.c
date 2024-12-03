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

int main()
{
    //Testing file reader
    readTextFile("files/names/spanish/first_syllable_spanish.txt"
                 ,showString, NULL);
    printf("\n");
    readTextFile("files/names/spanish/second_syllable_spanish.txt"
                 ,showString, NULL);

    //Testing string concatenation
    char name[20];
    concatenateStrings("A", name);
    concatenateStrings("gus", name);
    showString(name, NULL);

    //Testing string comparator
    printf("%d\n", compareString("A","A"));

    //Testing tree functions
    BinaryTree tree;
    createTree(&tree);
    printf("%d\n", treeIsEmpty(&tree));
    //TODO: fix compareString to work with "insertIntoTree"
    insertIntoTree(&tree, name, sizeof(name), compareString);
    printf("%d\n", treeIsEmpty(&tree));

    //Testing list functions
    LinkedList list;
    createList(&list);
    printf("\n%d\n", listIsEmpty(&list));
    unsigned intAux = 1;
    addItem(&list, (void *) &intAux, sizeof(unsigned));
    intAux = 5;
    addItem(&list, (void *) &intAux, sizeof(unsigned));
    intAux = 3;
    addItem(&list, (void *) &intAux, sizeof(unsigned));

    //Testing text file to list
    LinkedList firstSyllables;
    createList(&firstSyllables);
    loadTextFileToList("files/names/spanish/first_syllable_spanish.txt"
                       , &firstSyllables);

    LinkedList secondSyllables;
    createList(&secondSyllables);
    loadTextFileToList("files/names/spanish/second_syllable_spanish.txt"
                       , &secondSyllables);

    //Testing name generator
    LinkedList srcLists;
    createList(&srcLists);
    addItem(&srcLists, &firstSyllables, sizeof(LinkedList*));
    addItem(&srcLists, &secondSyllables, sizeof(LinkedList*));
    LinkedList dest;
    createList(&dest);
    generateName(&srcLists, &dest, 2000);

    return 0;
}
