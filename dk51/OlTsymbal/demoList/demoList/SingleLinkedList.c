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
	else { return NULL; }

	return theResult;
}

IntNode *SLNodeAtIndex(const IntList *aList, int anIndex)
{
	IntNode *theResult = NULL;

	if (NULL != aList && anIndex <= aList->count)
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
//  SingleLinkedList.c
//  demoList
//
//  Created by Tsymbal Olexandr.
//  Copyright © 2016 OlTsymbal. All rights reserved.
//
IntNode *SLInsertNodeAtIndex(IntList *aList, IntNode *aNewNode, int anIndex) {
	if (NULL == aList || NULL == aNewNode) // checking does the list and Node is empty?
	{
		return NULL;
	}
	if (NULL == aList->head && NULL == aList->tail) 
	{
		aList->head = aList->tail = aNewNode; //if the head and the tail is empty our node will be put on this place
		return aNewNode;
	}
	else
	{
		if (NULL != aList &&  anIndex <= aList->count)//cheking does the list is empty and an index 
		{
			IntNode *theNode = aList->head;
			while (theNode != NULL) {// cheking is there the Node?
				if (anIndex == 0)   // if index=0, we put our node on first plase in List
				{
					aNewNode->nextNode = theNode;//aNewNode link to theNode
					aList->head = aNewNode;//put aNewNode on a head of aList
					aList->count += 1;//increase count
					return aNewNode;
				}
				else
				{
					IntNode *aPrevNode = SLNodeAtIndex(aList, anIndex - 1);
					aNewNode->nextNode = aPrevNode->nextNode;//aNewNode shoul link to that which previous node refers
					aPrevNode->nextNode = aNewNode;// previous node link to aNewNode
					aList->count += 1;//increase count 
					return aNewNode;
				}
			}
		}
		return aNewNode;
	}
}

IntNode *SLRemovedNodeAtIndex(IntList *aList, int anIndex) 
{
	if (NULL == aList)//checking input parameters
	{
		return NULL;
	}
	if (NULL != aList &&  anIndex <= aList->count)//checking input parameters
	{
			IntNode *removedNode = SLNodeAtIndex(aList, anIndex);//find the node with needed index
			if (anIndex == 0)
			{
				aList->head = removedNode->nextNode;//head of aList have a link to the nextNode
				SLFreeIntNode(removedNode);// free node
				aList->count -= 1;//decrease count 
				return removedNode;
			}
			else
			{
				IntNode *PredNode = SLNodeAtIndex(aList, anIndex - 1);//find the previous node
				PredNode->nextNode = removedNode->nextNode;//previous node has a link to link of removedNode
				SLFreeIntNode(removedNode);//free node
				aList->count -= 1;//decrease count
				return removedNode;
			}
	}
}