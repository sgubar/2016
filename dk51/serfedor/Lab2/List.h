//
//  List.h
//  Lab2
//
//  Created by ergey Fedorenko on 3/23/16.
//  Copyright © 2016 Sergey Fedorenko. All rights reserved.
//


#ifndef List_h
#define List_h

#include <stdio.h>


typedef struct __IntNode IntNode;

typedef struct __IntList
{
	IntNode *head;
	IntNode *tail;
	int count;
}IntList;

extern const int kListError;

IntList *CreateList();
void FreeList(IntList *aList);

IntNode *AddNode(IntList *aList, IntNode *aNewNode);

int SLCountList(const IntList *aList);
IntNode *NodeAtIndex(const IntList *aList, int aIndex);


#endif /* List_h */
