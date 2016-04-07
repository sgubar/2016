//  FunList.c
//  Laba. 2 var. 13
//
//  Created by Ryzhenkov Serhii on 30/03/16.
//  Copyright © 2016 Ryzhenkov Serhii. All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include "Fun.h"
#include "FunList.h"

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

void PrintList(IntList *List)		//функция для вывода списка
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

IntNode *InsertNode(IntList *List, IntNode *NewNode, int anIndex) {		//вствляет ноду по заданому индексу
	if (NULL == List || NULL == NewNode || anIndex>List->count + 1)
	{
		return NULL;
	}
	else
	{
		if (0 == anIndex) {
			NewNode->nextNode = List->head;
			List->head = NewNode;
			List->count++;
			return(NewNode);
		}
		else {
			IntNode *theNode = NodeAtIndex(List, anIndex);
			IntNode *PreviosNode = NodeAtIndex(List, anIndex - 1);
			NewNode->nextNode = PreviosNode->nextNode;
			PreviosNode->nextNode = NewNode;
			List->count++;
			return NewNode;
		}
	}
}

IntNode *RemovedNode(IntList *List, int anIndex) {
	if (anIndex < List->count) {
		if ((NULL == List) || (anIndex>List->count))
		{
			return NULL;
		}
		else
		{
			if (anIndex == 0) {
				IntNode *theNode = NodeAtIndex(List, anIndex);
				List->head = NodeAtIndex(List, anIndex + 1);
				List->count -= 1;
				return theNode;
			}
			else {
				IntNode *theNode = NodeAtIndex(List, anIndex);
				IntNode *PreviosNode = NodeAtIndex(List, anIndex - 1);
				if (anIndex == List->count) List->tail = PreviosNode;
				PreviosNode->nextNode = theNode->nextNode;
				List->count -= 1;
				return theNode;
			}
		}
	}
}  // удаление ноды

