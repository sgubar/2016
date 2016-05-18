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
IntNode *SLInsertNodeAtIndex(IntList *aList, IntNode *aNewNode, int anIndex)//Insert node at index func realization 
{
      if (SLCountList(aList) < anIndex ||aList == NULL || aNewNode ==NULL) // check: if number of elemnets > than variable anIndex||list is empty||existance of our Node
        
            return NULL;
	

      if (anIndex == 0 && aList->head == NULL && aList->tail == NULL )//our list is empty 
        	
            aList->head= aList->tail = aNewNode;
        
    else
    {
                
        IntNode *theNode = SLNodeAtIndex(aList, anIndex-1);
        
        aNewNode->nextNode=theNode->nextNode; //new node will connect to the nextone
        theNode->nextNode= aNewNode; //prev node connecte to the new one       
        aList->count += 1;
        
        return aNewNode;
    }
} 
IntNode *SLRemovedNodeAtIndex(IntList *aList, int anIndex)//node removing at index func realization
{
if( SLCountList(aList) < anIndex)//check if our element exists 
    return NULL;
else
    {
          
        IntNode *theNode = SLNodeAtIndex(aList, anIndex -1);//node that stands before node that we want to delete

        theNode->nextNode=theNode->nextNode->nextNode;//connect prev node to the next node
    
        aList->count--;
  
    }
}
