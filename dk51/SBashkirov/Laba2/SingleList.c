//
//  SingleList.c
//  Laba 2
//
//  Created by Stanislav Bashkirov on 3/21/16.
//  Copyright © 2016 Stanislav Bashkirov. All rights reserved.
//

#include "SingleList.h"
#include "SingleNode.h"
#include <stdlib.h>

const int ListError = -1;

IntList *CreateList()
{
	IntList *theList = (IntList *)malloc(sizeof(IntList));

	theList->head = NULL;
	theList->tail = NULL; 
	theList->count = 0; 

	return theList;
}

void FreeList(IntList *aList)
{
	if (NULL == aList)
	{
		return;
	}

	IntNode *theNode = aList->head;

	while (NULL != theNode)
	{
		IntNode *theNodeToBeFree = theNode;
		theNode = theNode->nextNode;

		free(theNodeToBeFree);
	}

	free(aList);
}

IntNode *NodeAdd(IntList *aList, IntNode *aNewNode)
{
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

int CountList(const IntList *aList)
{
	int theResult = ListError;

	if (NULL != aList)
	{
		theResult = aList->count;
	}

	return theResult;
}

IntNode *NodeAtIndex(const IntList *aList, int anIndex)
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
IntNode *RemovedNodeAtIndex(IntList *aList, int anIndex)
{
	if ((NULL == aList) || (anIndex>aList->count))
	{
		return NULL;
	}
	else
	{
		if (0 == anIndex)
		{
			IntNode *RemovedNode = aList->head;
			aList->head = NodeAtIndex(aList, anIndex + 1);
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
