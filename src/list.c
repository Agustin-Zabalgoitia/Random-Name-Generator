#include "../include/list.h"

void createList(LinkedList *list)
{
    *list = NULL;
}

int listIsEmpty(const LinkedList *list)
{
    return *list == NULL;
}

void clearList(LinkedList *list)
{
    while(*list){
        ListNode *aux = *list;

        *list = aux->nextNode;
        free(aux->data);
        free(aux);
    }
}

unsigned getListSize(const LinkedList *list)
{
    unsigned n = 0;
    while(*list)
    {
        n++;
        list = &(*list)->nextNode;
    }
    return n;
}

int peek(const LinkedList *list, void *dest, unsigned destSize)
{
    if (*list == NULL)
        return IS_NULL;

    copyMemory(dest, (*list)->data, destSize);
    return OK;
}

int getItem(const LinkedList *list, unsigned index, void *dest
            , unsigned destSize)
{
    if (*list == NULL)
        return IS_NULL;

    while((*list)->nextNode && (index--)>0)
        list = &(*list)->nextNode;

    copyMemory(dest, (*list)->data, destSize);
    return OK;
}

int addItem(LinkedList *list, void *data, unsigned dataSize)
{
    while(*list)
        list = &(*list)->nextNode;

    ListNode *newNode;
    if( (newNode = (ListNode *)malloc(sizeof(ListNode))) == NULL
        ||  (newNode->data = malloc(dataSize)) == NULL)
    {
        free(newNode);
        return OUT_OF_MEMORY;
    }

    copyMemory(newNode->data, data, dataSize);
    newNode->dataSize = dataSize;
    newNode->nextNode = NULL;

    *list = newNode;

    return OK;
}
