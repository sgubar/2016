//  FunList.h
//  Laba. 2 var. 13
//
//  Created by Ryzhenkov Serhii on 30/03/16.
//  Copyright © 2016 Ryzhenkov Serhii. All rights reserved.

typedef struct __IntNode IntNode;
typedef struct __IntList
{
	IntNode *head;
	IntNode *tail;
	int count;
}IntList;

IntList *Create_L();

void FreeList(IntList *aList);
int CountList(const IntList *aList);
void PrintList(IntList *aList);

IntNode *AddNode(IntList *aList, IntNode *aNewNode);
IntNode *NodeAtIndex(const IntList *aList, int aIndex);

IntNode *InsertNode(IntList *aList, IntNode *aNewNode, int anIndex);
IntNode *RemovedNode(IntList *aList, int anIndex);

#pragma once
