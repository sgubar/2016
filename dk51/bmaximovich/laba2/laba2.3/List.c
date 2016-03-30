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
