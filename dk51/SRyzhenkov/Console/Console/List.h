//  List.h
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

void FreeList(IntList *List);
int CountList(const IntList *List);
void PrintList(IntList *List);

IntNode *InsertNode(IntList *aList, IntNode *aNewNode, int anIndex);
IntNode *RemovedNode(IntList *aList, int anIndex);
IntNode *AddNode(IntList *List, IntNode *NewNode);
IntNode *NodeAtIndex(const IntList *List, int aIndex);


#pragma once
