//
//  SingleList.h
//  Laba 2
//
//  Created by Stanislav Bashkirov on 3/21/16.
//  Copyright © 2016 Stanislav Bashkirov. All rights reserved.
//

#ifndef SingleList_h
#define SingleList_h

#include <stdio.h>

typedef struct __IntNode IntNode;

typedef struct __IntList
{
	IntNode *head;
	IntNode *tail;
	int count;
}IntList;

extern const int ListError;


IntList *ListCreate();
void FreeList(IntList *aList);

IntNode *NodeAdd(IntList *aList, IntNode *aNewNode);

int CountList(const IntList *aList);
IntNode *NodeAtIndex(const IntList *aList, int aIndex);

IntNode *InsertNodeAtIndex(IntList *aList, IntNode *aNewNode, int anIndex);
IntNode *RemovedNodeAtIndex(IntList *aList, int anIndex);

#endif /* SingleList_h */
