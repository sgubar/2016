
//  CreateSLList.c
//  Created by Dima Humeniuk on 05/06/16.
//  Copyright © 2016 Dima Humeniuk. All rights reserved.
//

#include "CreateList.h"
#include <stdio.h>


IntNode *CreateNode(int value)
{
	IntNode *aNewNode = (IntNode*)malloc(sizeof(IntNode));

	aNewNode->value = value;
	aNewNode->nextNode = NULL;
	//printf("Created new node...%d bytes allocated...\n", sizeof(IntNode));

	return aNewNode;
}


IntList *CreateSLList()
{
	IntList *theList = (IntList*)malloc(sizeof(IntList));

	theList->head = NULL;
	theList->tail = NULL;
	theList->count = 0;
	printf("Created a single linked list...%d bytes allocated...\n", sizeof(IntList));

	return theList;
}

IntNode *AddNode(IntList *theList, IntNode *aNewNode)
{
	if (NULL == theList || NULL == aNewNode)//check the input
	{
		return NULL;
	}

	if (theList->head == NULL || theList->head == NULL)//if the list is empty...
	{
		theList->head = theList->tail = aNewNode;

		//now theList->head points to NULL
	}
	else
	{
		IntNode *tailOLD;
		tailOLD = theList->tail;//save current 'tail'

		tailOLD->nextNode = aNewNode;//link the nodes
		//now theList->head points to the first node

		theList->tail = aNewNode;//define new value of tail
	}

	theList->count++;
	return aNewNode;
}

void PrintList(IntList *theList)
{
	int i = 0;
	IntNode *theNode = theList->head;
	printf("Printing the list...\n");
	while (theNode != NULL)
	{
		printf("node[%d].value=%d\n", i, theNode->value);
		theNode = theNode->nextNode;
		i++;
	}
}


void MoveNodes(IntList *theList, IntNode *NodeA, IntNode *NodeB)
{
	printf("Moving nodes...\n");

	IntNode *theNode = theList->head;
	int NodeAvalue = NodeA->value;//save the value of one of the nodes

	while (theNode != NULL)
	{

		if (theNode == NodeA)
		{

			theNode->value = NodeB->value;
			break;
		}
		theNode = theNode->nextNode;
	}

	while (theNode != NULL)
	{

		if (theNode == NodeB)
		{

			theNode->value = NodeAvalue;
			break;
		}
		theNode = theNode->nextNode;
	}
	return;
}



void doSelectionSort(IntList *theList)
{
	printf("Sorting the list using selection algorithm...\n");
	int i = 0;
	int y = 1;
	IntNode *theNode = theList->head;
	IntNode *MinNode = theNode;
	while (y <= theList->count - 1)
	{
		while (i <= theList->count - y)
		{

			if (theNode->value < MinNode->value)
			{
				int a = theNode->value;
				MoveNodes(theList, theNode, MinNode);
				MinNode->value = a;
			}
			theNode = theNode->nextNode;
			i++;
		}
		i = 0;
		PrintList(theList);
		theNode = MinNode->nextNode;//new 'head' of the list
		MinNode = theNode;
		y++;
	}
}