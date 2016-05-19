//
//  CreateSLList.h
//  Created by Dima Humeniuk on 05/06/16.
//  Copyright © 2016 Dima Humeniuk. All rights reserved.
//

#ifndef CreateSLList_h
#define CreateSLList_h

#include <stdio.h>

typedef struct _IntNode IntNode;

typedef struct _IntNode
{
	int value;
	IntNode *nextNode;
};


typedef struct _IntList
{
	IntNode *head;
	IntNode *tail;
	int count;
}IntList;

IntNode *CreateNode(int value);
IntList *CreateSLList();
IntNode *AddNode(IntList *theList, IntNode *aNewNode);

void PrintList(IntList *theList);

void doSelectionSort(IntList *theList);

#endif