//
//  SingleLinkedList.h
//  Lab2
//
//  Created by Andrew Toporivskiy on 6/26/16.
//  Copyright © 2016 Andrew Toporivskiy. All rights reserved.
//

#ifndef SingleLinkedList_h
#define SingleLinkedList_h

#include <stdio.h>

// Predeclaration
typedef struct __IntNode IntNode;

typedef struct __IntList
{
	IntNode *head;
	IntNode *tail;
	int count;
}IntList;

extern const int ListError;

//Interface
//Create/delete a list
IntList *CreateList();
void FreeList(IntList *aList);

IntNode *AddNode(IntList *aList, int aValue);

IntList *MinMax_Swapper(IntList *aList);
IntList *DeleteByKey(IntList *aList, int aKey);

int CountList(const IntList *aList);
IntNode *NodeAtIndex(const IntList *aList, int aIndex);

IntNode *InsertNodeAtIndex(IntList *aList, IntNode *aNewNode, int anIndex);
IntNode *RemovedNodeAtIndex(IntList *aList, int anIndex);

#endif /* SingleLinkedList_h */