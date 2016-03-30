#include <stdlib.h>
#include <stdio.h>
#include "Function.h"
#include "FunctionList.h"

IntNode *CreateN(int perevod) {
	IntNode *theResult = (IntNode *)malloc(sizeof(IntNode));
	theResult->value = perevod;
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

int doFindIndexMin(IntNode *theList) {
	int a;
	int min;
	int max;
	int IndexMinimum = 0;
	a = CountList(theList);
	
	IntNode *MinNode = NodeAtIndex(theList, IndexMinimum);

	
	min = NodeAtIndex(theList, IndexMinimum)->value;


	for (int k = 0; k < a; k++)
	{

		if (min >= MinNode->value)
		{
			min = MinNode->value;
			IndexMinimum=k;
		}
		MinNode = MinNode->nextNode;

	}
	printf("Minimum %d\n", IndexMinimum);
	return(IndexMinimum);
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

void doSorting(IntNode *theList, int IndexMin, int IndexMax) {
	int a;
	int j = 0;
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
	for (int j = MinIndex; j < MaxIndex; j++) {
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
	printf("Sorting List\n");
	doPrintList(theList);
}