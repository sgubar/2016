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
	theList->name = ' ';
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

//
IntNode *SLInsertNodeAtIndex(IntList *aList, IntNode *aNewNode, int anIndex)
{
	if (aList == NULL || aNewNode == NULL || anIndex>aList->count + 1)
		{
		return NULL;
		}
	
		else
		{
		if (anIndex == 0)
			{
			aNewNode->nextNode = aList->head;
			aList->head = aNewNode;
			aList->count += 1;
			
			}
		else
			{
			IntNode *PrevNode = SLNodeAtIndex(aList, anIndex - 1);
			if (aList->count + 1 == anIndex) aList->tail = aNewNode;
			else aNewNode->nextNode = PrevNode->nextNode;
			PrevNode->nextNode = aNewNode;
			aList->count += 1;
			
			}
		return(aNewNode);
		}
	}
IntNode *SLRemovedNodeAtIndex(IntList *aList, int anIndex)
{
	if ((aList == NULL) || (anIndex>aList->count))
		{
		return NULL;
		}
	else
		{
		IntNode *RemovedNode = SLNodeAtIndex(aList, anIndex);
		if (anIndex == 0)
			{
			aList->head = SLNodeAtIndex(aList, anIndex + 1);
			aList->count -= 1;
			}
		else
			{
			IntNode *PrevNode = SLNodeAtIndex(aList, anIndex - 1);
			if (aList->count == anIndex) aList->tail = PrevNode;
			PrevNode->nextNode = RemovedNode->nextNode;
			aList->count -= 1;
			}
		return(RemovedNode);
		}
}

void doPrintSLList(const IntList *aList)
{
	for (int i = 0; i < SLCountList(aList); i++)
	{
		IntNode *theNode = SLNodeAtIndex(aList, i);
		if (NULL != theNode)
		{
			printf("node[%d] = [%d] [%c] \n", i, theNode->value, theNode->name);

		}
	}
}

void *SLSwapNode( IntList *getList, int getIndex, IntList *postList, int postIndex)
{
	IntNode *getNode;
	IntNode *postNode;
	char swapOne,swapTwo;

	swapOne = SLNodeName(SLNodeAtIndex(postList, postIndex));
	swapTwo = SLNodeName(SLNodeAtIndex(getList, getIndex));

	getNode = SLNodeAtIndex(getList, getIndex);
	postNode = SLNodeAtIndex(postList, postIndex);



	postNode->name = swapTwo;
	getNode->name = swapOne;

	return false;

}

void swapMaxMinNode(IntList *aList)
{
	char max = SLNodeName(SLNodeAtIndex(aList,0));
	int maxIndex = 0;
	char min = SLNodeName(SLNodeAtIndex(aList, 0));
	int minIndex = 0;
	for (int index = 0; index < SLCountList(aList); index++)
	{
		if (max < SLNodeName(SLNodeAtIndex(aList, index)))
		{
			max = SLNodeName(SLNodeAtIndex(aList, index));
			maxIndex = index;
		}
		if (min > SLNodeName(SLNodeAtIndex(aList, index)))
		{
			min = SLNodeName(SLNodeAtIndex(aList, index));
			minIndex = index;
		}
	}

	SLSwapNode(aList, maxIndex, aList, minIndex);

	
}

void sort(IntList *aList) 
{
	bool sorted = false;
	char max = SLNodeName(SLNodeAtIndex(aList, 0));

	while (!sorted)
	{
		sorted = true;
		for (int index = 0; index < SLCountList(aList) - 1; index++)
		{
			max = SLNodeName(SLNodeAtIndex(aList, index));
			if (max > (SLNodeName(SLNodeAtIndex(aList, index + 1))))
			{
				SLSwapNode(aList, index, aList, index + 1);
				sorted = false;
			}
		}
	}

}
