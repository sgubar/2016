//  list.c
// 
//
//  Created by Bogdan Maximovich on 23/03/16.
//  Copyright © 2016 Bogdan Maximovich. All rights reserved.
//

#include "list.h"
#include "Node.h"
#include <stdlib.h>
#include "DoubleList.h"

const int ListError = -1;

//Create a list
IntList *CreateList()
{
	//Allocate memory for the list structure
	IntList *theList = (IntList *)malloc(sizeof(IntList));
	theList->head = NULL; //not head
	theList->tail = NULL; // not tail
	theList->count = 0; //initial value of count is zero - no elements in the list

	return theList;
}

void FreeList(IntList *aList)
{
	// Check the input parameter
	if (NULL == aList)
	{
		return;
	}

	//Remove all elements
	IntNode *theNode = aList->head;

	while (NULL != theNode)
	{
		IntNode *theFreeNode = theNode;
		theNode = theNode->nextNode;

		free(theFreeNode);
	}

	free(aList);
}

IntNode *AddNode(IntList *aList, IntNode *aNewNode)
{
	if (NULL == aList || NULL == aNewNode)
	{
		return NULL;
	}

	//Add node to end of the list

	if (NULL == aList->head && NULL == aList->tail)
	{
		aList->head = aList->tail = aNewNode;
	}
	else
	{
		IntNode *theTail = aList->tail;
		aList->tail = aNewNode;

		if (NULL != theTail)
		{
			theTail->nextNode = aList->tail;
		}
	}

	aList->count += 1;

	return aNewNode;
}

int CountList(const IntList *aList)
{
	int theResult = 0;

	if (NULL != aList)
	{
		theResult = aList->count;
	}

	return theResult;
}

IntNode *IndexNode(const IntList *aList, int anIndex)
{
	IntNode *theResult = NULL;

	if (NULL != aList && anIndex < aList->count)
	{
		int i = 0;
		IntNode *theNode = aList->head;

		do
		{
			if (i == anIndex)
			{
				theResult = theNode;
				break;
			}

			i++;
			theNode = theNode->nextNode; // link to next node

		} while (NULL != theNode);
	}

	return theResult;
}
IntNode *InsertNodeAtIndex(IntList *aList, IntNode *aNewNode, int anIndex)
{
	// Check the input parameter
	if (NULL == aList || NULL == aNewNode || anIndex>aList->count + 1)
	{
		return NULL;
	}

	else
	{
		if (0 == anIndex)
		{
			aNewNode->nextNode = aList->head;
			aList->head = aNewNode;
			aList->count += 1;
		}
		else
		{
			IntNode *PrevNode = IndexNode(aList, anIndex - 1);
			if (anIndex == aList->count + 1) aList->tail = aNewNode;
			else aNewNode->nextNode = PrevNode->nextNode;
			PrevNode->nextNode = aNewNode;
			aList->count += 1;
		}
		return(aNewNode);
	}
}
IntNode *RemovedNodeAtIndex(IntList *aList, int anIndex)
{
	if ((NULL == aList) || (anIndex>aList->count))
	{
		return NULL;
	}
	else
	{
		IntNode *RemovedNode = IndexNode(aList, anIndex);
		if (0 == anIndex)
		{
			aList->head = IndexNode(aList, anIndex + 1);
			aList->count -= 1;
		}
		else
		{
			IntNode *PrevNode = IndexNode(aList, anIndex - 1);
			if (anIndex == aList->count) aList->tail = PrevNode;
			PrevNode->nextNode = RemovedNode->nextNode;
			aList->count -= 1;

		}
		return(RemovedNode);
	}
}

int *ValueNode(const IntList *aList, int anValue)
{
	int i = 0;
	if (NULL != aList)
	{
		IntNode *theNode = aList->head;

		do
		{
			if (theNode->value == anValue)
			{
				break;
			}

			i++;
			theNode = theNode->nextNode; // link to next node

		} while (NULL != theNode);
	}
	return i;
}


IntNode *findMaxNode(const IntList *aList) {
	IntNode *currentNode = aList->head;
	IntNode *maxNode = currentNode;
	do {
		if (currentNode->value >= maxNode->value) {
			maxNode = currentNode;
		}
		currentNode = currentNode->nextNode;
	} while (NULL != currentNode);
	return maxNode;
}
IntNode *findMinNode(const IntList *inputList) {
	IntNode *currentNode = inputList->head;
	IntNode *minNode = currentNode;
	do {
		if (currentNode->value <= minNode->value) {
			minNode = currentNode;
		}
		currentNode = currentNode->nextNode;
	} while (NULL != currentNode);
	return minNode;
}

IntList *swapNodeAtList(IntList *inputList) {
	IntNode *minNode = findMinNode(inputList);
	IntNode *maxNode = findMaxNode(inputList);
	int minvalue = minNode->value;
	minNode->value = maxNode->value;
	maxNode->value = minvalue;
	return inputList;
}