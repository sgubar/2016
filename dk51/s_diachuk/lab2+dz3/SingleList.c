#include "SingleList.h"
#include "SingleNode.h"
#include <stdlib.h>

const int ListError = -1;

CharList *ListCreate()
{
	CharList *theList = (CharList *)malloc(sizeof(CharList));

	theList->head = NULL;
	theList->tail = NULL;
	theList->count = 0;

	return theList;
}

void FreeList(CharList *aList)
{
	if (NULL == aList)
	{
		return;
	}

	CharNode *theNode = aList->head;

	while (NULL != theNode)
	{
		CharNode *theNodeToBeFree = theNode;
		theNode = theNode->nextNode;

		free(theNodeToBeFree);
	}

	free(aList);
}

CharNode *NodeAdd(CharList *aList, char *aValue)
{
	if (NULL == aList)
	{
		return NULL;
	}

	CharNode *aNewNode = (CharNode *)malloc(sizeof(CharNode));

	aNewNode->value = aValue;
	aNewNode->nextNode = NULL;

	if (NULL == aList->head && NULL == aList->tail)
	{
		aList->head = aList->tail = aNewNode;
	}
	else
	{
		CharNode *theTail = aList->tail;
		aList->tail = aNewNode;

		if (NULL != theTail)
		{
			theTail->nextNode = aList->tail;
		}
	}

	aList->count += 1;

	return aNewNode;
}

int CountList(const CharList *aList)
{
	int theResult = ListError;

	if (NULL != aList)
	{
		theResult = aList->count;
	}

	return theResult;
}

CharNode *NodeAtIndex(const CharList *aList, int anIndex)
{
	CharNode *theResult = NULL;

	if (NULL != aList && anIndex < aList->count)
	{
		int i = 0;
		CharNode *theNode = aList->head;

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

CharNode *InsertNodeAtIndex(CharList *aList, CharNode *aNewNode, int anIndex)
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
			CharNode *PrevNode = NodeAtIndex(aList, anIndex - 1);
			if (anIndex == aList->count + 1) aList->tail = aNewNode;
			else
			{
				aNewNode->nextNode = PrevNode->nextNode;
				PrevNode->nextNode = aNewNode;
			}
			aList->count += 1;
		}
		return(aNewNode);
	}
}
CharNode *RemovedNodeAtIndex(CharList *aList, int anIndex)
{
	if ((NULL == aList) || (anIndex>aList->count))
	{
		return NULL;
	}
	else
	{
		CharNode *RemovedNode = NodeAtIndex(aList, anIndex);
		if (0 == anIndex)
		{
			aList->head = NodeAtIndex(aList, anIndex + 1);
			aList->count -= 1;
		}
		else
		{
			CharNode *PrevNode = NodeAtIndex(aList, anIndex - 1);
			if (anIndex == aList->count) aList->tail = PrevNode;
			PrevNode->nextNode = RemovedNode->nextNode;
			aList->count -= 1;

		}
		return(RemovedNode);
	}
}

//dz3
void theBubbleSorting(CharNode *theList, int Count)//funcion for sorting list(the bubble sorting)
{
	for (int theWord = Count - 1; theWord > 1; theWord--)
	{
		for (int anIndex = 0; anIndex < theWord; anIndex++)//cycle from the first element to the last, with the increase in the index by 1
		{
			if (strlen(NodeAtIndex(theList, anIndex)->value) > strlen(NodeAtIndex(theList, anIndex + 1)->value))//if the value of the current node more than the value of the next node- assign value current node to the next node.
			{
				InsertNodeAtIndex(theList, RemovedNodeAtIndex(theList, anIndex), anIndex + 1);
			}
		}
	}

}
