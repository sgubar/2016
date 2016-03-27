//
//  SingleLinkedList.h
//  demoList
//
//  Created by Bogdan Maximovich on 23/03/16.
//  Copyright © 2016 Bogdan Maximovich. All rights reserved.
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

extern const int kSLListError;

//Interface
//Create/delete a list
IntList *SLCreateList();
void SLFreeList(IntList *aList);

IntNode *SLAddNode(IntList *aList, IntNode *aNewNode);

int SLCountList(const IntList *aList);
IntNode *SLNodeAtIndex(const IntList *aList, int aIndex);
IntList *createDoubleList(IntList *aList);

#endif /* SingleLinkedList_h */
