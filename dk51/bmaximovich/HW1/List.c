//  list.c
//
//
//  Created by Bogdan Maximovich on 15/05/16.
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
void *InsertNodeAtIndex(IntList *InsertList, IntNode *InsertNode, int index)
{

	if (  InsertNode != NULL &&InsertList!=NULL && index<=InsertList->count + 1&&index>=0)
	{
		if (0 != index)
		{
			IntNode *Previous = IndexNode(InsertList, index - 1);
			if (index == InsertList->count + 1) InsertList->tail = InsertNode;
			else InsertNode->nextNode = Previous->nextNode;
			Previous->nextNode = InsertNode;
			InsertList->count += 1;
		}
		else
		{
			InsertNode->nextNode = InsertList->head;
			InsertList->head = InsertNode;
			InsertList->count += 1;
		}
	}

}
void *RemovedNodeAtIndex(IntList *InsertList, int InsertNode)
{
        if (NULL != InsertList && InsertNode<InsertList->count&&InsertNode>=0)
{
   IntNode *RemovedNode = IndexNode(InsertList, InsertNode);
        if (0 != InsertNode)
{
   IntNode *PrevNode = IndexNode(InsertList, InsertNode - 1);
       if (InsertNode == InsertList->count) InsertList->tail = PrevNode;
   PrevNode->nextNode = RemovedNode->nextNode;
   InsertList->count -= 1;
}
       else
{

InsertList->head = IndexNode(InsertList, InsertNode + 1);
InsertList->count -= 1;

}
}
      else
{
       return NULL;
}
}


int *ValueNode(const IntList *aList, int anValue)
{
	int i = 0;
	int found = 0;
	if (NULL != aList)
	{
		IntNode *theNode = aList->head;

		do
		{
			if (theNode->value == anValue)
			{
			    found = 1;
				break;
			}

			i++;
			theNode = theNode->nextNode; // link to next node

		} while (NULL != theNode);
	}
	if(found == 1){
        return i;
	}else{
        return -1;
	}
}
