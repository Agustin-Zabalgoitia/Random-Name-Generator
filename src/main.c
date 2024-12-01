#include <stdio.h>
#include <stdlib.h>

#include "../include/fileManager.h"
#include "../include/str.h"
#include "../include/binaryTree.h"
#include "../include/list.h"

void showString(void *str)
{
    printf("%s", (char*) str);
}

int main()
{
    //Testing file reader
    readTextFile("files/names/spanish/first_syllable_spanish.txt",showString);
    printf("\n");
    readTextFile("files/names/spanish/second_syllable_spanish.txt",showString);

    //Testing string concatenation
    char name[20];
    concatenateStrings("A", "gus", name);
    showString(name);

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

    return 0;
}
