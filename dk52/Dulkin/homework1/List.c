#include "List.h"
#include "Node.h"
#include <stdlib.h>

// Constants
const int kSLListError = -1;

//Create/delete a list
IntList *CreateList()
{
	//Allocate memory for the list structure
	IntList *NewList = (IntList *)malloc(sizeof(IntList));

	//Clean internal data
	NewList->head = NULL; //<!- not head
	NewList->tail = NULL; //<!- not tail
	NewList->count = 0; //<!- initial value of count is zero - no elements in the list
	
// or
//	bzero(NewList, sizeof(IntList));
	
	return NewList;
}

void SetFree(IntList *InList)
{
	// Check the input parameter
	if (NULL == InList)
	{
		return;
	}

	//1. Remove all elements
	IntNode *theNode = InList->head;
	
	while (NULL != theNode)
	{
		IntNode *theNodeToBeFree = theNode;
		theNode = theNode->nextNode;
	
		free(theNodeToBeFree);
	}

	//2. Free memory for the List structure
	free(InList);
}

IntNode *AddNode(IntList *InList, IntNode *aNewNode)
{
	// Check the input parameter
	if (NULL == InList || NULL == aNewNode)
	{
		return NULL;
	}
	
	//Add the new node to end of the list
	
	// a b c d e + G = a b c d e G
	
	if (NULL == InList->head && NULL == InList->tail)
	{
		//The list is empty
		InList->head = InList->tail = aNewNode;
	}
	else
	{
		IntNode *theTail = InList->tail;
		InList->tail = aNewNode;
	
		if (NULL != theTail)
		{
			theTail->nextNode = InList->tail;
		}
	}

	InList->count += 1;
	
	return aNewNode;
}

int ListSize(const IntList *InList)
{
	int theResult = kSLListError;

	if (NULL != InList)
	{
		theResult = InList->count;
	}

	return theResult;
}

IntNode *NodeAt(const IntList *InList, int anIndex)
{
	IntNode *theResult = NULL;

	if (NULL != InList && anIndex < InList->count)
	{
		int i = 0;
		IntNode *theNode = InList->head;
	
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
//  Created by Bashkirov Stanislav on 3/16/16.
//  Copyright © 2016 Bashkirov Stanislav. All rights reserved.
//
IntNode *InsertAt(IntList *InList, IntNode *aNewNode, int anIndex)
{
	// Check the input parameter
	if (NULL == InList || NULL == aNewNode || anIndex>InList->count+1)
	{
		return NULL;
	}

	else
	{
		if (0 == anIndex)
		{
			aNewNode->nextNode = InList->head;
			InList->head = aNewNode;
			InList->count += 1;
		}
		else
		{
			IntNode *PrevNode = NodeAt(InList, anIndex - 1);
			if (anIndex == InList->count + 1) InList->tail = aNewNode;
			else aNewNode->nextNode = PrevNode->nextNode;
			PrevNode->nextNode = aNewNode;
			InList->count += 1;
		}
		return(aNewNode);
	}
}
IntNode *DeleteAt(IntList *InList, int anIndex)
{
	if ((NULL == InList) || (anIndex>InList->count))
	{
		return NULL;
	}
	else
	{
		IntNode *RemovedNode = NodeAt(InList, anIndex);
		if (0 == anIndex)
		{
			InList->head = NodeAt(InList, anIndex+1);
			InList->count -= 1;
		}
		else
		{
			IntNode *PrevNode = NodeAt(InList, anIndex - 1);
			if (anIndex == InList->count) InList->tail = PrevNode;
			PrevNode->nextNode = RemovedNode->nextNode;
			InList->count -= 1;
		}
		return(RemovedNode);
	}
}
