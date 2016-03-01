//
//  SingleLinkedList.h
//  demoList
//
//  Created by Slava Gubar on 3/1/16.
//  Copyright © 2016 Slava Gubar. All rights reserved.
//

#ifndef SingleLinkedList_h
#define SingleLinkedList_h

#include <stdio.h>

// Predeclaration
typedef struct __IntNode IntNode;

// The node declaration
struct __IntNode
{
	int value;
	IntNode *nextNode;
};

typedef struct __IntList
{
	IntNode *head;
	IntNode *tail;
	int count;
}IntList;

const int kSLListError = -1;

//Interface
//Create/delete a list
const IntList *createSLList();
void freeList(IntList *aList);

const IntNode *addNode(IntList *aList, IntNode *aNewNode);

int countList(const IntList *aList);
const IntNode *nodeAtIndex(const IntList *aList, int aIndex);

#endif /* SingleLinkedList_h */
