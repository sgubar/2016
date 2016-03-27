#include <stdio.h>
#include <stdlib.h>
#include "Function.h"
#include "FunctionList.h"

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
			printf("node[%d].value = %d\n", i, theNode->value);
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
				aList->head = NodeAtIndex(aList, anIndex+1);
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
