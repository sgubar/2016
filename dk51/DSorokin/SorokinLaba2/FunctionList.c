#include <stdio.h>
#include <stdlib.h>
#include "Function.h"
#include "FunctionList.h"


IntList *CreateList()
{
	IntList *theList = (IntList *)malloc(sizeof(IntList));
	theList->head = NULL; //<!- not head
	theList->tail = NULL; //<!- not tail
	theList->count = 0; //<!- initial value of count is zero - no elements in the list
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


IntNode *AddNode(IntList *aList, IntNode *aNewNode)
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

IntNode *NodeAtIndex(const IntList *aList, int anIndex)
{
	IntNode *theResult = NULL;

	if (NULL != aList && anIndex < aList->count)
	{
		int i = 0;
		IntNode *theNode = aList->head;

		do
		{
			if (i == anIndex) //<!- index was found
			{
				theResult = theNode; //<! - our node
				break;
			}

			i++; // increase index
			theNode = theNode->nextNode; //<! - go to next node

		} while (NULL != theNode);
	}

	return theResult;
}
