#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

#include <stdlib.h>
#include "str.h"
#include "errorNumbers.h"

#define allocateNodeMemory( X , Y , Z , W ) (                       \
                ( ( X ) = (typeof( X ))malloc( Y ) ) == NULL ||     \
                ( ( Z ) = malloc( W ) ) == NULL  ?                  \
                      free( X ), 0 : 1  )

typedef struct sTreeNode
{
    void *data;
    unsigned dataSize;
    struct sTreeNode *left, *right;
} TreeNode;

typedef TreeNode* BinaryTree;

void createTree(BinaryTree *);
void emptyTree(BinaryTree *);
int treeIsEmpty(const BinaryTree *);
int insertIntoTree(BinaryTree *, const void *, unsigned
                   ,int (*)(const void *, const void *));

#endif // BINARYTREE_H_INCLUDED
