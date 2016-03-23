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