//
//  SingleList.c
//  Lab2
//
//  Created by Timoshenko Serj on 4/7/16.
//  Copyright (C) 2016 Timoshenko Serj. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "SingleNode.h"
#include "SingleList.h"

const int ListError = -1;

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

int CountList(const IntList *aList)
{
	int theResult = ListError;

	if (NULL != aList)
	{
		theResult = aList->count;
	}

	return theResult;
}

void doPrintList(IntList *aList)
{
	
	for (int i = 0; i < CountList(aList); i++)
	{
		IntNode *theNode = NodeAtIndex(aList, i);
		if (NULL != theNode)
		{
			printf("node[%d].Word  = %s\n", i, theNode->CharWord);
		}
	}
	
}

IntNode *InsertNode(IntList *aList, IntNode *aNewNode, int anIndex) {
	if (NULL == aList || NULL == aNewNode || anIndex>aList->count + 1)
	{
		return NULL;
	}
	else
	{
		if (0 == anIndex) {
			aNewNode->nextNode = aList->head;
			aList->head = aNewNode;
			aList->count++;
			return(aNewNode);
		}
		else {
			IntNode *theNode = NodeAtIndex(aList, anIndex);
			IntNode *PreviosNode = NodeAtIndex(aList, anIndex - 1);
			aNewNode->nextNode = PreviosNode->nextNode;
			PreviosNode->nextNode = aNewNode;
			aList->count++;
			return aNewNode;
		}
	}
}

IntNode *RemovedNode(IntList *aList, int anIndex) {
	if (anIndex < aList->count) {
		if ((NULL == aList) || (anIndex>aList->count))
		{
			return NULL;
		}
		else
		{
			if (anIndex == 0) {
				IntNode *theNode = NodeAtIndex(aList, anIndex);
				aList->head = NodeAtIndex(aList, anIndex + 1);
				aList->count -= 1;
				return theNode;
			}
			else {
				IntNode *theNode = NodeAtIndex(aList, anIndex);
				IntNode *PreviosNode = NodeAtIndex(aList, anIndex - 1);
				if (anIndex == aList->count) aList->tail = PreviosNode;
				PreviosNode->nextNode = theNode->nextNode;
				aList->count -= 1;
				return theNode;
			}
		}
	}
}

void TheMinAndTheMax(IntNode *theList) {
	int a, min;
	int j = 0;
	int InMin = 0;
	int InMax = 0;
	int RemovedAtIndex = 0;
	a = CountList(theList);
	for (int j = 0; j < a; j++) {

		IntNode *TheMinNode = NodeAtIndex(theList, InMin);
		min = NodeAtIndex(theList, InMin)->value;

		for (int k = InMin; k < a; k++)
		{

			if (min >= TheMinNode->value)
			{
				min = TheMinNode->value;
				RemovedAtIndex = k;
			}

			TheMinNode = TheMinNode->nextNode;

		}

		InsertNode(theList, RemovedNode(theList, RemovedAtIndex), InMin);
		InMin++;

	}
	printf("Edited list\n\n");
	doPrintList(theList);
}

void theBubbleSorting(IntNode *theList, int Count)//funcion for sorting list(the bubble sorting)
{
	for (int theWord = Count - 1; theWord > 1; theWord--)
	{
		for (int anIndex = 0; anIndex < theWord; anIndex++)//cycle from the first element to the last, with the increase in the index by 1
		{
			if (NodeAtIndex(theList, anIndex)-> value > NodeAtIndex(theList, anIndex + 1)->value)//if the value of the current node more than the value of the next node- assign value current node to the next node.
			{
				int theTmp = NodeAtIndex(theList, anIndex)->value;//variable, which stores the maximum value of the list
					NodeAtIndex(theList, anIndex)->value = NodeAtIndex(theList, anIndex + 1)->value;
					NodeAtIndex(theList, anIndex + 1)->value = theTmp;
			}
		}
	}
printf("The bubble sorting\n\n");
doPrintList(theList);
}
