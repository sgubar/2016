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

IntNode *SLInsertNodeAtIndex(IntList *aList, IntNode *aNewNode, int anIndex)
{
	IntNode *theNode = aList->head;
	IntNode *aPrevNode = NULL;
	IntNode *aNextNode = NULL;
	if(NULL != aList && anIndex <= aList->count) //checking imput elements 
	{
		if (anIndex == 0) // add node as the first element 
		{
			aList->head = aNewNode; //NewNode - first element of the list
			aNewNode->nextNode = theNode; // NewNode goes to next node - node, that was first element before
		}
		if(anIndex == aList->count) //add new node to the and of the list
		{
			IntNode *theTail = aList->tail;
			theTail->nextNode = aList->tail;
			aList->tail = aNewNode;
		}
		if (anIndex>=0 && anIndex<=aList->count) //index between head and tail
		{
			aPrevNode = theNode;
			aNextNode = theNode->nextNode;
			aPrevNode->nextNode = aNewNode;
			aNewNode->nextNode = aNextNode;
		}
	}
	else 
	{
			printf("Error \n");
	}
	return aNewNode;
}

IntNode *SLRemovedNodeAtIndex(IntList *aList, int anIndex)
{
	IntNode *deleteNode = aList->head; //node that must be removed
	IntNode *aPrevNode = NULL;
	IntNode *aNextNode = NULL;
	if(NULL != aList && anIndex <= aList->count) //checking imput elements 
	{
		if (anIndex == 0) // remove the first node 
		{
			aList->head = deleteNode;
			deleteNode->nextNode = aNextNode;
			aList->head = aNextNode; //NextNode - first element of the list
		}
		if(anIndex == aList->count) //remove the node from the and of the list
		{
			IntNode *theTail = aList->tail;
			theTail->nextNode = aList->tail;
			aList->tail = deleteNode;
			aPrevNode->nextNode = deleteNode;
			aList->tail = aPrevNode; //Previous node i the last element at the list
		}
		if (anIndex>=0 && anIndex<=aList->count) //index between head and tail
		{
			aPrevNode->nextNode = deleteNode;
			deleteNode->nextNode = aNextNode;
			aPrevNode->nextNode = aNextNode;
		}
	}
	else 
	{
		printf("Error \n");
	}
	return deleteNode;
}
