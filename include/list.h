#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdlib.h>
#include "utils.h"
#include "errorNumbers.h"

typedef struct sListNode
{
    void *data;
    unsigned dataSize;
    struct sListNode *nextNode;
} ListNode;

typedef ListNode *LinkedList;

void createList(LinkedList *);
int listIsEmpty(const LinkedList *);
void clearList(LinkedList *);
int peek(const LinkedList *, void *, unsigned);
int getItem(const LinkedList *, unsigned , void *, unsigned);
int addItem(LinkedList *, void *, unsigned);

#endif // LIST_H_INCLUDED
