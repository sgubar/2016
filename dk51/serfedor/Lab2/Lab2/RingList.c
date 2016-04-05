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
	theList->tail = theList->head;
	theList->count = 0;


	return theList;
}
RingList *doList()
{

	printf("Start to create a circular list \n");

	IntNode *theNode0 = CreateNode(10);
	IntNode *theNode1 = CreateNode(4);
	IntNode *theNode2 = CreateNode(3);
	IntNode *theNode4 = CreateNode(5);
	IntNode *theNode5 = CreateNode(1);
	IntNode *theNode6 = CreateNode(2);

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

IntNode *InsertNodeAtIndex(RingList *aList, IntNode *aNewNode, int anIndex){
	if (NULL == aList || NULL == aNewNode){
		return NULL;
	}

	if (NULL == aList->head && NULL == aList->tail){
		//The list is empty
		aList->head = aList->tail = aNewNode;
	}
	else{
		if (anIndex < aList->count){
			int i = 0;
			IntNode *theNode = aList->head;
			do{
				if (i == anIndex){ //<!- index was found
					aNewNode->nextNode = theNode->nextNode;
					theNode->nextNode = aNewNode;
					aList->count += 1;
					break;
				}
				i++; // increase index
				theNode = theNode->nextNode; //<! - go to next node

			} while (NULL != theNode);
		}
	}
	return aNewNode;
}

IntNode *RemovedNodeAtIndex(RingList *aList, int anIndex){
	if (anIndex < aList->count){
		int i = 0;
		IntNode *theNode = aList->head;
		do{
			if (i == anIndex){ //<!- index was found
				IntNode *aNextNode = theNode->nextNode;
				theNode->nextNode = aNextNode->nextNode;
				free(aNextNode);
				aList->count -= 1;
				break;
			}
			i++; // increase index
			theNode = theNode->nextNode; //<! - go to next node

		} while (NULL != theNode);
	}

}

RingList *MinMax(RingList *aList)
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

int doFindIndexMax(IntNode *theList) {
	int a;
	int max;
	int IndexMaximum = 0;
	a = CountList(theList);

	IntNode *MaxNode = NodeAtIndex(theList, IndexMaximum);

	max = NodeAtIndex(theList, IndexMaximum)->value;

	for (int k = 0; k < a; k++)
	{
		if (max <= MaxNode->value)
		{
			max = MaxNode->value;
			IndexMaximum = k;
		}

		MaxNode = MaxNode->nextNode;
	}
	printf("Maximum %d\n", IndexMaximum);
	return(IndexMaximum);
}
void doSortingValue(IntNode *theList, int IndexMin, int IndexMax) {
	int a = 0;
	int b = 0;
	int max;
	int min;

	int IndexRemoved = 0;
	a = CountList(theList);
	int MinIndex;
	int MaxIndex;

	if (IndexMin > IndexMax) {
		MinIndex = IndexMax;
		MaxIndex = IndexMin;
	}
	else {
		MinIndex = IndexMin;
		MaxIndex = IndexMax;
	}
	int IndexMinimum = MinIndex;
	for (int b = MinIndex; b < MaxIndex; b++) {
		IntNode *MinNode = NodeAtIndex(theList, IndexMinimum);
		min = NodeAtIndex(theList, IndexMinimum)->value;

		for (int k = IndexMinimum; k < IndexMax; k++)
		{

			if (min >= MinNode->value)
			{
				min = MinNode->value;
				IndexRemoved = k;
			}

			MinNode = MinNode->nextNode;

		}

		InsertNode(theList, RemovedNode(theList, IndexRemoved), IndexMinimum);
		IndexMinimum++;

	}
	printf("List after sorting\n");
	doPrintList(theList);
}
