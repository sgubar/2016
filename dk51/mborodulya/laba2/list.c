#include "list.h"
#include "node.h"
#include <stdlib.h>

const int ListError = -1;

FloatList *ListCreate()
{
	FloatList *theList = (FloatList *)malloc(sizeof(FloatList));

	theList->head = NULL;
	theList->tail = NULL;
	theList->count = 0;

	return theList;
}

void FreeList(FloatList *aList)
{
	if (NULL == aList)
	{
		return;
	}

	FloatNode *theNode = aList->head;

	while (NULL != theNode)
	{
		FloatNode *theNodeToBeFree = theNode;
		theNode = theNode->nextNode;

		free(theNodeToBeFree);
	}

	free(aList);
}

FloatNode *NodeAdd(FloatList *aList, float aValue)
{
	if (NULL == aList)
	{
		return NULL;
	}

	FloatNode *aNewNode = (FloatNode *)malloc(sizeof(FloatNode));

	aNewNode->value = aValue;
	aNewNode->nextNode = NULL;

	if (NULL == aList->head && NULL == aList->tail)
	{
		aList->head = aList->tail = aNewNode;
	}
	else
	{
		FloatNode *theTail = aList->tail;
		aList->tail = aNewNode;

		if (NULL != theTail)
		{
			theTail->nextNode = aList->tail;
		}
	}

	aList->count += 1;

	return aNewNode;
}

int CountList(const FloatList *aList)
{
	int theResult = ListError;

	if (NULL != aList)
	{
		theResult = aList->count;
	}

	return theResult;
}

FloatNode *NodeAtIndex(const FloatList *aList, int anIndex)
{
	FloatNode *theResult = NULL;

	if (NULL != aList && anIndex < aList->count)
	{
		int i = 0;
		FloatNode *theNode = aList->head;

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

FloatNode *InsertNodeAtIndex(FloatList *aList, FloatNode *aNewNode, int anIndex)
{
	// Check the input parameter
	if (NULL == aList || NULL == aNewNode || anIndex>aList->count + 1)
	{
		return NULL;
	}

	else
	{
		if (0 == anIndex)
		{
			aNewNode->nextNode = aList->head;
			aList->head = aNewNode;
			aList->count += 1;
		}
		else
		{
			FloatNode *PrevNode = NodeAtIndex(aList, anIndex - 1);
			if (anIndex == aList->count + 1) aList->tail = aNewNode;
			else aNewNode->nextNode = PrevNode->nextNode;
			PrevNode->nextNode = aNewNode;
			aList->count += 1;
		}
		return(aNewNode);
	}
}
FloatNode *RemovedNodeAtIndex(FloatList *aList, int anIndex)
{
	if ((NULL == aList) || (anIndex>aList->count))
	{
		return NULL;
	}
	else
	{
		FloatNode *RemovedNode = NodeAtIndex(aList, anIndex);
		if (0 == anIndex)
		{
			aList->head = NodeAtIndex(aList, anIndex + 1);
			aList->count -= 1;
		}
		else
		{
			FloatNode *PrevNode = NodeAtIndex(aList, anIndex - 1);
			if (anIndex == aList->count) aList->tail = PrevNode;
			PrevNode->nextNode = RemovedNode->nextNode;
			aList->count -= 1;

		}
		return(RemovedNode);
	}
}

FloatList *MinMax(FloatList *aList)
{
	FloatNode *min = aList->tail, *max = aList->head;
	int minIndex, maxIndex;
	for (int i = 0; i < aList->count;i++)
	{
		FloatNode *theNode=NodeAtIndex(aList,i);
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

FloatList *deleteKeys(FloatList *aList, float key1, float key2, float key3)
{
	for (int i = 0;i < aList->count;i++)
	{
		FloatNode *theNode = NodeAtIndex(aList, i);
		if ((theNode->value == key1) || (theNode->value == key2) || (theNode->value == key3))
		{
			RemovedNodeAtIndex(aList, i);
			free(theNode);
		}
	}
	return (aList);
}
