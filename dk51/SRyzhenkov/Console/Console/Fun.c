//  Fun.c
//  Laba. 2 var. 13
//
//  Created by Ryzhenkov Serhii on 30/03/16.
//  Copyright © 2016 Ryzhenkov Serhii. All rights reserved.

#include <stdlib.h>
#include <stdio.h>
#include "Fun.h"
#include "FunList.h"

IntNode *CreateNode(int converting) {
	IntNode *theResult = (IntNode *)malloc(sizeof(IntNode));
	theResult->value = converting;
	theResult->nextNode = NULL;
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

void distribution(IntNode *theList) {
	int count;
	int min;
	int j = 0;
	int max = NodeAtIndex(theList, 0)->value;
	int IndexMin = 0;
	int IndexMax = 0;
	int IndexRem = 0;
	int b = 0;
	count = CountList(theList);
	IntNode *TheNode = NodeAtIndex(theList, 0);

	for (int b = 0; b < count; b++) {
		if (max < TheNode->value)
		{
			max = TheNode->value;
			IndexMax = b;
		}
		TheNode = TheNode->nextNode;
	}

	printf("IndexMax = %d \n", IndexMax);
	
	for (int j = 0; j < IndexMax; j++) {

		IntNode *MinNode = NodeAtIndex(theList, IndexMin);
		min = NodeAtIndex(theList, IndexMin)->value;

		for (int k = IndexMin; k < IndexMax; k++)
		{

			if (min >= MinNode->value)
			{
				min = MinNode->value;
				IndexRem = k;
			}

			MinNode = MinNode->nextNode;

		}

		InsertNode(theList, RemovedNode(theList, IndexRem), IndexMin);
		IndexMin++;

	}
	printf("Distribution: \n");
	PrintList(theList);
}

void UpdatedValue(IntNode *theList) {
	int count;
	int min = 0;
	int max = 0;
	int IndexMin = 0;
	int IndexMax = 0;
	count = CountList(theList);

	IntNode *MinNode = NodeAtIndex(theList, IndexMin);
	IntNode *MaxNode = NodeAtIndex(theList, IndexMax);


	for (int k = IndexMin; k < count; k++)
	{

		if (max <= MaxNode->value)
		{
			max = MaxNode->value;

		}

		if (min >= MinNode->value)
		{
			min = MinNode->value;
		}

		MinNode = MinNode->nextNode;
		
	}
}