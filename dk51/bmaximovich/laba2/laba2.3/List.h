#pragma once
//
//  List.h
//
//
//  Created by Bogdan Maximovich on 23/03/16.
//  Copyright © 2016 Bogdan Maximovich. All rights reserved.
//

#ifndef list
#define list

#include <stdio.h>
#include "Node.h"
typedef struct __IntList IntList;

typedef struct __IntList
{
	IntNode *head;
	IntNode *tail;
	int count;
}
IntList;

//Create a list

IntList *CreateList();

void FreeList(IntList *aList);

IntNode *AddNode(IntList *aList, IntNode *aNewNode);

int CountList(const IntList *aList);

IntNode *IndexNode(const IntList *aList, int aIndex);

//Create a New list with double value


int CountList(const IntList *aList);

int *ValueNode(const IntList *aList, int anValue);

IntNode *MaxNode(const IntList *aList);
IntNode *MinNode(const IntList *aList);
IntNode *InsertNodeAtIndex(IntList *aList, IntNode *aNewNode, int anIndex);
IntNode *RemovedNodeAtIndex(IntList *aList, int anIndex);
#endif /* List */
