//
//  RingList.h
//  Lab2
//
//  Created by Sergey Fedorenko on 3/23/16.
//  Copyright © 2016 Sergey Fedorenko. All rights reserved.
//


#ifndef RingList_h
#define RingList_h

#include <stdio.h>


typedef struct __IntNode IntNode;

typedef struct __RingList
{
	IntNode *head;
	IntNode *tail;
	int count;
}RingList;

extern const int kListError;

RingList *CreateList();
void FreeList(RingList *aList);

IntNode *AddNode(RingList *aList, IntNode *aNewNode);

int SLCountList(const RingList *aList);
IntNode *NodeAtIndex(const RingList *aList, int aIndex);


#endif /* RingList_h */
