#include "../include/binaryTree.h"

void createTree(BinaryTree *tree)
{
    *tree = NULL;
}

void emptyTree(BinaryTree *tree)
{
    if(!tree)
        return;

    emptyTree(&(*tree)->left);
    emptyTree(&(*tree)->right);
    free((*tree)->data);
    free(*tree);
    *tree = NULL;
}

int treeIsEmpty(const BinaryTree *tree)
{
    return *tree == NULL;
}

int insertIntoTree(BinaryTree *tree, const void *data, unsigned dataSize
                   ,int (*cmp)(const void *, const void *))
{
    TreeNode *newNode;
    int rc;

    while(*tree)
    {
        if((rc = cmp(data, (*tree)->data)) < 0)
            tree = &(*tree)->left;
        else if (rc > 0)
            tree = &(*tree)->right;
        else
            return DUPLICATED_KEY;
    }

    if(!allocateNodeMemory(newNode, sizeof(newNode), newNode->data, dataSize))
        return OUT_OF_MEMORY;

    copyMemory(newNode->data, data, dataSize);
    newNode->dataSize = dataSize;
    newNode->left = newNode->right = NULL;
    *tree = newNode;

    return OK;
}
