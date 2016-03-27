//
//  RingList.c
//  Lab2
//
//  Created by  on 3/23/16.
//  Copyright © 2016 Sergey fedorenko. All rights reserved.
//
//
#include "RingList.h"
#include "Node.h"
#include <stdlib.h>

// Constants
const int kListError = -1;

//Create/delete a list
RingList *CreateList()
{

	RingList *theList = (RingList *)malloc(sizeof(RingList));


	theList->head = NULL;
	theList->tail = NULL;
	theList->count = 0;


	return theList;
}

void FreeList(RingList *aList)
{
	// Check the input parameter
	if (NULL == aList)
	{
		return;
	}

	//1. Remove all elements
	IntNode *theNode = aList->head;

	while (NULL != theNode)
	{
		IntNode *theNodeFree = theNode;
		theNode = theNode->nextNode;

		free(theNodeFree);
	}

	//2. Free memory for the List structure
	free(aList);
}

IntNode *AddNode(RingList *aList, IntNode *aNewNode)
{
	// Check the input parameter
	if (NULL == aList || NULL == aNewNode)
	{
		return NULL;
	}


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

int CountList(const RingList *aList)
{
	int theResult = kListError;

	if (NULL != aList)
	{
		theResult = aList->count;
	}

	return theResult;
}

IntNode *NodeAtIndex(const RingList *aList, int anIndex)
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
			theNode = theNode->nextNode;

		} while (NULL != theNode);
	}

	return theResult;
}

IntNode *InsertNodeAtIndex(RingList *aList, IntNode *aNewNode, int anIndex){
    // Check the input parameter
	if (NULL == aList || NULL == aNewNode || anIndex>aList->count+1)
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
			return(aNewNode);
		}
		else
		{
			IntNode *PrevNode = NodeAtIndex(aList, anIndex - 1);
			PrevNode->nextNode = aNewNode;
			if (anIndex == aList->count + 1) aList->tail = aNewNode;
			else aNewNode->nextNode = PrevNode->nextNode;
			aList->count += 1;
			return(aNewNode);
		}
	}
}

IntNode *RemovedNodeAtIndex(RingList *aList, int anIndex){
    if ((NULL == aList) || (anIndex>aList->count))
	{
		return NULL;
	}
	else
	{
		if (0 == anIndex)
		{
			IntNode *RemovedNode = aList->head;
			aList->head = NodeAtIndex(aList, anIndex+1);
			aList->count -= 1;
			return(RemovedNode);
		}
		else
		{
			IntNode *PrevNode = NodeAtIndex(aList, anIndex - 1);
			IntNode *RemovedNode = NodeAtIndex(aList, anIndex);
			if (anIndex == aList->count) aList->tail = PrevNode;
			PrevNode->nextNode = RemovedNode->nextNode;
			aList->count -= 1;
			return(RemovedNode);
		}
	}
}
