#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdlib.h>
#include "str.h"
#include "errorNumbers.h"

typedef struct sListNode
{
    void *data;
    unsigned dataSize;
    struct sListNode *nextNode;
} ListNode;

typedef ListNode *LinkedList;

/**
* Create an empty list.
* @param list - pointer to the list to be created
**/
void createList(LinkedList *list);
/**
* Check if a list is empty.
* @param list - pointer to the list to check if it's empty
* @return 1 if the list is empty, 0 otherwise
**/
int listIsEmpty(const LinkedList *list);
/**
* Removes all the elements from the list.
* @param list - pointer to the list to be cleared
**/
void clearList(LinkedList *list);
/**
* Returns the number of elements present in the list
* @param list - pointer to the given list
* @return The size of the given list
**/
unsigned getListSize(const LinkedList *list);
/**
* Get the first element of the list.
* @param list - pointer to the list
* @param dest - pointer to the destination where the element will be stored
* @param destSize - size of the destination
**/
int peek(const LinkedList *list, void *dest, unsigned destSize);
/**
* Get the item in the 'index' position from the list. Doesn't remove the item
* from the list
* @param list - pointer to the list
* @param index - position of the element
* @param dest - pointer to the destination where the element will be stored
* @param destSize - size of the destination
**/
int getItem(const LinkedList *list, unsigned index, void *dest
            , unsigned destSize);
/**
* Get the size of the item in the 'index' position. Doesn't get the item itself.
* @param list - pointer to the list
* @param index - position of the element
* @return The size of the item in the 'index' position
**/
unsigned getItemSize(const LinkedList *list, unsigned index);
/**
* Adds an item at the end of the list.
* @param list - pointer to the list
* @param data - the data to be stored on the list
* @param dataSize - the size of the data to be stored on the list
* @return OK if the item was added successfully or OUT_OF_MEMORY if there's not
 enough memory left to store the data
**/
int addItem(LinkedList *list, void *data, unsigned dataSize);

#endif // LIST_H_INCLUDED
