//
//  SingleLinkedList.c
//  demoList
//
//  Created by Slava Gubar on 3/1/16.
//  Copyright © 2016 Slava Gubar. All rights reserved.
//

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
		SLFreeIntNode(theNode);
		printf("HI");
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

	if (NULL != aList && anIndex <= aList->count) //check for errors
	{
		int i = 0;
		IntNode *theNodePrev = NULL;
		IntNode *theNodeNext = NULL;
		IntNode *theNode = aList->head;

		if (anIndex == aList->count) //insert node in the end of the list;
		{
			SLAddNode(aList, aNewNode);
			return 0;
		}

		if (anIndex == 0) ////insert node in the beginning of the list;
		{
			IntNode *theHead = aList->head;
			aList->head = aNewNode;
			aNewNode->nextNode = theNode;
		}

		do //insert node between the first and the last nodes of the list
		{
			if (i == (anIndex-1) ) 
			{
				theNodePrev = theNode; // the node before the new node (previous node)
				theNodeNext = theNode->nextNode; //the node which goes after the 'previous' node (next node)
				theNodePrev->nextNode = aNewNode; // insert the new node after the previous one
				aNewNode->nextNode = theNodeNext; //insert the 'next' node after the new one
				
				break;
			}

			i++; // increase index
			theNode = theNode->nextNode; // go to next node

		} while (NULL != theNode);
		

		aList->count += 1;

	}

	else

	{
		printf("Error: index exceeds the number of nodes.\n");
	}

	return aNewNode;
	
}

IntNode *SLRemovedNodeAtIndex(IntList *aList, int anIndex)
{

	if (NULL != aList && anIndex <= aList->count) //check for errors
	{
		int i = 0;
		IntNode *theNodePrev = NULL;
		IntNode *theNodeNext = NULL;
		IntNode *NodeToFree = NULL;
		IntNode *theNode = aList->head;

		do //insert node between the first and the last nodes of the list
		{
			if (i == (anIndex - 1))
			{
				theNodePrev = theNode;
				NodeToFree = theNodePrev->nextNode;
				
				printf("1\n");
			}
			if (i == (anIndex))
			{
				theNode = NodeToFree;
				theNodePrev->nextNode = NodeToFree->nextNode;
				SLFreeIntNode(NodeToFree);
				aList->count -= 1;
				printf("2\n");
				break;
			}
			

			i++; // increase index
			theNode = theNode->nextNode;// go to next node

		} while (NULL != theNode);
		
		return 0;
	}
}
