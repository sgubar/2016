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