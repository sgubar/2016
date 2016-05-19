//
//  RingList.c
//  Lab2
//
//  Created by  on 4/7/16.
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
	theList->tail = theList->head;
	theList->count = 0;


	return theList;
}
RingList *doList()
{

	printf("Start to create a Ring list \n");

	IntNode *theNode0 = CreateNode(10);
	IntNode *theNode1 = CreateNode(2);
	IntNode *theNode2 = CreateNode(3);
	IntNode *theNode4 = CreateNode(5);
	IntNode *theNode5 = CreateNode(30);
	IntNode *theNode6 = CreateNode(4);

	RingList *theList = CreateList();

	AddNode(theList, theNode0);
	AddNode(theList, theNode1);
	AddNode(theList, theNode2);
	AddNode(theList, theNode4);
	AddNode(theList, theNode5);
	AddNode(theList, theNode6);
	printf("number of elements: %d\n", CountList(theList));

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

IntNode *InsertNodeAtIndex(RingList *aList, IntNode *aNewNode, int anIndex) {
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

IntNode *RemovedNodeAtIndex(RingList *aList, int anIndex) {
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

/*IntNode *findMinNode(const RingList *inputList) {
	IntNode *currentNode = inputList->head;
	IntNode *minNode = currentNode;
	do {
		if (currentNode->value <= minNode->value) {
			minNode = currentNode;
		}
		currentNode = currentNode->nextNode;
	} while (NULL != currentNode);
	return minNode;
}

IntNode *findMaxNode(const RingList *aList) {
	IntNode *currentNode = aList->head;
	IntNode *maxNode = currentNode;
	do {
		if (currentNode->value >= maxNode->value) {
			maxNode = currentNode;
		}
		currentNode = currentNode->nextNode;
	} while (NULL != currentNode);
	return maxNode;
}

RingList *swapNodeAtList(RingList *inputList) {
	IntNode *minNode = findMinNode(inputList);
	IntNode *maxNode = findMaxNode(inputList);
	int minvalue = minNode->value;
	minNode->value = maxNode->value;
	maxNode->value = minvalue;
	return inputList;
}

void doSortingValue(IntNode *theList) {
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

		InsertNodeAtIndex(theList, RemovedNodeAtIndex(theList, RemovedAtIndex), InMin);
		InMin++;

	}

}

*/


//Homework3
void theBubbleSorting(RingList*theList, int Count)//funcion for sorting list(the bubble sorting)
{
	for (int theWord = Count - 1; theWord > 1; theWord--)
	{
		for (int anIndex = 0; anIndex < theWord; anIndex++)//cycle from the first element to the last, with the increase in the index by 1
		{
			if (NodeAtIndex(theList, anIndex)->value > NodeAtIndex(theList, anIndex + 1)->value)//if the value of the current node more than the value of the next node- assign value current node to the next node.
			{
				int theTmp = NodeAtIndex(theList, anIndex)->value;//variable, which stores the maximum value of the list
				NodeAtIndex(theList, anIndex)->value = NodeAtIndex(theList, anIndex + 1)->value;
				NodeAtIndex(theList, anIndex + 1)->value = theTmp;
			}
		}
	}
	printf("The bubble sorting\n\n");
}