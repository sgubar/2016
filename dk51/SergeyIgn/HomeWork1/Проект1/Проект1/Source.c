#include "SingleLinkedList.h"
#include "SingleLinkedNode.h"
#include <stdlib.h>

// Constants
const int kSLListError = -1;

//Create/delete a list
IntList *SLCreateList()
{
	//Allocate memory for the list structure
	IntList *theList = (IntList *)malloc(sizeof(IntList));

	//Clean internal data
	theList->head = NULL; //<!- not head
	theList->tail = NULL; //<!- not tail
	theList->count = 0; //<!- initial value of count is zero - no elements in the list

						// or
						//	bzero(theList, sizeof(IntList));

	return theList;
}

void SLFreeList(IntList *aList)
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
		IntNode *theNodeToBeFree = theNode;
		theNode = theNode->nextNode;

		free(theNodeToBeFree);
	}

	//2. Free memory for the List structure
	free(aList);
}

IntNode *SLAddNode(IntList *aList, IntNode *aNewNode)
{
	// Check the input parameter
	if (NULL == aList || NULL == aNewNode)
	{
		return NULL;
	}

	//Add the new node to end of the list

	// a b c d e + G = a b c d e G

	if (NULL == aList->head && NULL == aList->tail)
	{
		//The list is empty
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

int SLCountList(const IntList *aList)
{
	int theResult = kSLListError;

	if (NULL != aList)
	{
		theResult = aList->count;
	}

	return theResult;
}

IntNode *SLInsertNodeAtIndex(IntList *aList, IntNode *aNewNode, int anIndex);
if (SLCountList(const IntList *aList) < anIndex || aList == NULL || aNewNode == NULL)// перевырка чи буде входити комірка комірка яку ми хочемо додати у існуючий список
	return NULL;
if (anIndex == 0 && aList->head == NULL && aList->tail == NULL)// перевірка чи існує загалі список
aList->head = aNewNode;

else
{
	IntNode *theNode = SLNodeAtIndex(aList, anIndex);
	aNewNode->theNode = theNode->nextNode;
	IntNode *theNode = SLNodeAtIndex(aList, anIndex - 1);//знаходимо індекс(номер) комірки попередньої до тої, що ми додали
	theNode->nextNode = aNewNode;//створюємо звязок між нодою що була на місці тієї що ми додали і тієї що ми додали
	aList->count += 1;

	return aNewNode;
}

IntNode *SLRemovedNodeAtIndex(IntList *aList, int anIndex);

if (SLCountList(const IntList *aList) < anIndex || aList == NULL || aNewNode == NULL)//аналогічно як у першій функції робимо перевірки
	return NULL;
if (anIndex == 0 && aList->head == NULL && aList->tail == NULL)
aList->head = aNewNode;
else
{
	IntNode *theNode = SLNodeAtIndex(aList, anIndex - 1);//знаходимо адресу комірки, яка знаходиться перед тією, яку ми хочемо видалити.
	theNode->nextNode = theNode->nextNode->nextNode;//задаємо що попередня нода вказує на наступну ноду тієї, яку ми видалили
}


IntNode *SLNodeAtIndex(const IntList *aList, int anIndex)
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
