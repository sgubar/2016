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

typedef struct IntNode IntNode;

typedef struct IntList
{
	IntNode *head;
	IntNode *tail;
	int count;
}IntList;
extern const int ListError;


//Create a list

IntList *CreateList();

void FreeList(IntList *aList);

IntNode *AddNode(IntList *aList, IntNode *aNewNode);

int CountList(const IntList *aList);

IntNode *IndexNode(const IntList *aList, int aIndex);

IntList *CreateDoubleList(IntList *aList);

#endif /* List */