#include <stdio.h>
#include <stdlib.h>

#include "fileManager.h"
#include "str.h"
#include "binaryTree.h"

void showString(void *str)
{
    printf("%s", (char*) str);
}

int main()
{
    //Testing file reader
    readTextFile("src/names/spanish/first_syllable_spanish.txt",showString);
    printf("\n");
    readTextFile("src/names/spanish/second_syllable_spanish.txt",showString);

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

    return 0;
}
