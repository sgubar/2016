//
//  SingleNode.c
//  Lab2
//
//  Created by Timoshenko Serj on 3/29/16.
//  Copyright (C) 2016 Timoshenko Serj. All rights reserved.
//

#include "SingleNode.h"
#include "SingleList.h"
#include <stdlib.h>
#include <stdio.h>


IntNode *CreateNode(int theValue, char *CharWord)
{
	IntNode *theResult = (IntNode *)malloc(sizeof(IntNode));
	theResult->value = theValue;
	theResult->nextNode = NULL;
	theResult->CharWord = CharWord;
	return theResult;
}

void FreeIntNode(IntNode *Node)
{
	if (NULL != Node)
	{
		free(Node);
	}
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