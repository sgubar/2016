//
//  SingleLinkedList.c
//  Lab2
//
//  Created by Andrew Toporivskiy on 6/26/16.
//  Copyright © 2016 Andrew Toporivskiy. All rights reserved.
//

#include "SingleLinkedList.h"
#include "SingleLinkedNode.h"
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

IntNode *AddNode(IntList *aList, int aValue)
{
	if (NULL == aList)
	{
		return NULL;
	}

	IntNode *aNewNode = (IntNode *)malloc(sizeof(IntNode));

	aNewNode->value = aValue;
	aNewNode->nextNode = NULL;

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
		}
		else
		{
			IntNode *PrevNode = NodeAtIndex(aList, anIndex - 1);
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
		IntNode *RemovedNode = NodeAtIndex(aList, anIndex);
		if (0 == anIndex)
		{
			aList->head = NodeAtIndex(aList, anIndex + 1);
			aList->count -= 1;
		}
		else
		{
			IntNode *PrevNode = NodeAtIndex(aList, anIndex - 1);
			if (anIndex == aList->count) aList->tail = PrevNode;
			PrevNode->nextNode = RemovedNode->nextNode;
			aList->count -= 1;

		}
		return(RemovedNode);
	}
}

IntList *MinMax_Swapper(IntList *aList)
{
	IntNode *min = aList->head, *max = aList->head;
	int minIndex, maxIndex;
	for (int i = 1; i < aList->count; i++)
	{
		IntNode *theNode = NodeAtIndex(aList, i);
		if (min->value > theNode->value)
		{
			min = theNode;
			minIndex = i;
		}
		else
			if (max->value < theNode->value)
			{
				max = theNode;
				maxIndex = i;
			}
	}
	if (minIndex < maxIndex)
	{
		RemovedNodeAtIndex(aList, maxIndex);
		RemovedNodeAtIndex(aList, minIndex);
		InsertNodeAtIndex(aList, max, minIndex);
		InsertNodeAtIndex(aList, min, maxIndex);
	}
	else
	{
		RemovedNodeAtIndex(aList, minIndex);
		RemovedNodeAtIndex(aList, maxIndex);
		InsertNodeAtIndex(aList, min, maxIndex);
		InsertNodeAtIndex(aList, max, minIndex);
	}
	return aList;
}

IntList *DeleteByKey(IntList *aList, int aKey)
{
	for (int i = 0; i < aList->count; i++)
	{
		IntNode *theNode = NodeAtIndex(aList, i);
		if (theNode->value == aKey)
		{
			RemovedNodeAtIndex(aList, i);
			free(theNode);
		}
	}
	return (aList);
}