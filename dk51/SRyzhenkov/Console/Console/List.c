//  List.c
//  Laba. 2 var. 13
//
//  Created by Ryzhenkov Serhii on 30/03/16.
//  Copyright © 2016 Ryzhenkov Serhii. All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include "Myfunction.h"
#include "List.h"

const int ListError = -1;

IntList *Create_L()	// создание и выделение памяти для списка
{
	IntList *theList = (IntList *)malloc(sizeof(IntList));
	theList->head = NULL; 
	theList->tail = NULL; 
	theList->count = 0; 
	return theList;
}

void FreeList(IntList *List)	//очистка списка
{
	if (NULL == List)
	{
		return;
	}
	IntNode *theNode = List->head;

	while (NULL != theNode)
	{
		IntNode *theNodeToBeFree = theNode;
		theNode = theNode->nextNode;
		free(theNodeToBeFree);
	}
	free(List);
}

int CountList(const IntList *List)	
{
	int theResult = ListError;

	if (NULL != List)
	{
		theResult = List->count;
	}

	return theResult;
}

void PrintList(IntList *List)//функция для вывода списка
{
	for (int i = 0; i < CountList(List); i++)
	{
		IntNode *theNode = NodeAtIndex(List, i);
		if (NULL != theNode)
		{
			printf("node[%d].value = %d\n", i, theNode->value);
		}
	}
}

IntNode *InsertNode(IntList *aList, IntNode *aNewNode, int anIndex) {
	if (NULL == aList || NULL == aNewNode || anIndex>aList->count + 1)
	{
		return NULL;
	}
	else
	{
		if (0 == anIndex) {
			aNewNode->nextNode = aList->head;
			aList->head = aNewNode;
			aList->count++;
			return(aNewNode);
		}
		else {
			IntNode *theNode = NodeAtIndex(aList, anIndex);
			IntNode *PreviosNode = NodeAtIndex(aList, anIndex - 1);
			aNewNode->nextNode = PreviosNode->nextNode;
			PreviosNode->nextNode = aNewNode;
			aList->count++;
			return aNewNode;
		}
	}
}

IntNode *RemovedNode(IntList *aList, int anIndex) {
	if (anIndex < aList->count) {
		if ((NULL == aList) || (anIndex>aList->count))
		{
			return NULL;
		}
		else
		{
			if (anIndex == 0) {
				IntNode *theNode = NodeAtIndex(aList, anIndex);
				aList->head = NodeAtIndex(aList, anIndex + 1);
				aList->count -= 1;
				return theNode;
			}
			else {
				IntNode *theNode = NodeAtIndex(aList, anIndex);
				IntNode *PreviosNode = NodeAtIndex(aList, anIndex - 1);
				if (anIndex == aList->count) aList->tail = PreviosNode;
				PreviosNode->nextNode = theNode->nextNode;
				aList->count -= 1;
				return theNode;
			}
		}
	}
}