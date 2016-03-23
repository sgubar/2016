//
//  List.c
//  Lab2
//
//  Created by  on 3/23/16.
//  Copyright © 2016 Sergey fedorenko. All rights reserved.
//

#include "List.h"
#include "Node.h"
#include <stdlib.h>

// Constants
const int kListError = -1;

//Create/delete a list
IntList *CreateList()
{
	//Allocate memory for the list structure
	IntList *theList = (IntList *)malloc(sizeof(IntList));


	theList->head = NULL;
	theList->tail =theList-> head;
	theList->count = 0;


	return theList;
}

void FreeList(IntList *aList)
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

IntNode *AddNode(IntList *aList, IntNode *aNewNode)
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

int CountList(const IntList *aList)
{
	int theResult = kListError;

	if (NULL != aList)
	{
		theResult = aList->count;
	}

	return theResult;
}

IntNode *NodeAtIndex(const IntList *aList, int anIndex)
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

IntNode *InsertNodeAtIndex(IntList *aList, IntNode *aNewNode, int anIndex){
    IntNode *result = NULL;

    if (NULL == aList || NULL == aNewNode){
		return NULL;
	}

    if (NULL == aList->head && NULL == aList->tail){
		//The list is empty
		aList->head = aList->tail = aNewNode;
	}else{
        if(anIndex < aList->count){
            int i = 0;
            IntNode *theNode = aList->head;
            do{
			if (i == anIndex){ //<!- index was found
                result->nextNode=theNode->nextNode;
                theNode->nextNode=result;
                break;
			}
			i++; // increase index
			theNode = theNode->nextNode; //<! - go to next node

            }while (NULL != theNode);
        }
	}
	return result;
}

IntNode *RemovedNodeAtIndex(IntList *aList, int anIndex){
    if(anIndex < aList->count){
        int i = 0;
            IntNode *theNode = aList->head;
            do{
			if (i == anIndex){ //<!- index was found
                IntNode *aNextNode = theNode->nextNode;
                theNode->nextNode = aNextNode->nextNode;
                free(aNextNode);
                break;
			}
			i++; // increase index
			theNode = theNode->nextNode; //<! - go to next node

            }while (NULL != theNode);
    }
}
