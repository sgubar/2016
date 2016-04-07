//  Fun.c
//  Laba. 2 var. 13
//
//  Created by Ryzhenkov Serhii on 30/03/16.
//  Copyright © 2016 Ryzhenkov Serhii. All rights reserved.

#include <stdlib.h>
#include <stdio.h>
#include "Fun.h"
#include "FunList.h"

IntNode *CreateNode(int converting) {
	IntNode *Result = (IntNode *)malloc(sizeof(IntNode));
	Result->value = converting;
	Result->nextNode = NULL;
	return Result;
} // создание ноды (выделение памяти)

void FreeIntNode(IntNode *Node)
{
	if (NULL != Node)
	{
		free(Node);
	}
} // если выделили, то и должны очистить 

IntNode *AddNode(IntList *List, IntNode *NewNode)
{
	if (NULL == List || NULL == NewNode)
	{
		return NULL;
	}
	if (NULL == List->head && NULL == List->tail)
	{
		List->head = List->tail = NewNode;
	}
	else
	{
		IntNode *theTail = List->tail;
		List->tail = NewNode;

		if (NULL != theTail)
		{
			theTail->nextNode = List->tail;
		}
	}
	List->count += 1;
	return NewNode;
} // добавление ноды в список

IntNode *NodeAtIndex(const IntList *List, int anIndex)
{
	IntNode *theResult = NULL;

	if (NULL != List && anIndex < List->count)
	{
		int i = 0;
		IntNode *theNode = List->head;

		do
		{
			if (i == anIndex) 
			{
				theResult = theNode; 
				break;
			}

			i++; 
			theNode = theNode->nextNode; 

		} while (NULL != theNode);
	}

	return theResult;
} // функция для нахождения ноды по индексу

void distribution(IntNode *theList) {  //сортировка
	int count;
	int min;
	int i = 0;
	int max = NodeAtIndex(theList, 0)->value;
	int IndexMin = 0;
	int IndexMax = 0;
	int IndexRem = 0;
	int b = 0;
	count = CountList(theList);
	IntNode *TheNode = NodeAtIndex(theList, 0);

	for (int b = 0; b < count; b++) {  //цикл для нахождения максимального значения 
		if (max < TheNode->value)
		{
			max = TheNode->value;
			IndexMax = b;
		}
		TheNode = TheNode->nextNode;
	}

	printf("IndexMax = %d \n", IndexMax); // вывод значения ноды в которой находится наш максимум
	
	for (int i = 0; i < IndexMax; i++)  {	// цикл, который выставляет значения до максимального по возрастанию 

		IntNode *MinNode = NodeAtIndex(theList, IndexMin);
		min = NodeAtIndex(theList, IndexMin)->value;

		for (int k = IndexMin; k < IndexMax; k++)
		{

			if (min >= MinNode->value)
			{
				min = MinNode->value;
				IndexRem = k;
			}

			MinNode = MinNode->nextNode;

		}

		InsertNode(theList, RemovedNode(theList, IndexRem), IndexMin);
		IndexMin++;

	}
	printf("Distribution: \n");
	PrintList(theList);
}

void bubbleSort(IntNode *theList, int CountList)
{
	
	for (int theOut = CountList - 1; theOut > 1; theOut--)
	{
		for (int theIn = 0; theIn < theOut; theIn++)
		{
			if (NodeAtIndex(theList, theIn)->value > NodeAtIndex(theList, theIn+1)->value)
			{
				int theTmp = NodeAtIndex(theList, theIn)->value;
				NodeAtIndex(theList, theIn)->value = NodeAtIndex(theList, theIn + 1)->value;
				NodeAtIndex(theList, theIn + 1)->value = theTmp;
			}
		}
	}
	printf("bubbleSort\n");
	PrintList(theList);
}