//
//  SingleList.h
//  Lab2
//
//  Created by Timoshenko Serj on 3/29/16.
//  Copyright (C) 2016 Timoshenko Serj. All rights reserved.
//



#pragma once

#ifndef SingleList_H_INCLUDED
#define SingleList_H_INCLUDED


typedef struct __IntNode IntNode;
typedef struct __IntList
{
	IntNode *head;
	IntNode *tail;
	int count;
}IntList;

IntList *CreateList();

void FreeList(IntList *aList);
int CountList(const IntList *aList);
void doPrintList(IntList *aList);

IntNode *AddNode(IntList *aList, IntNode *aNewNode);
IntNode *NodeAtIndex(const IntList *aList, int anIndex);

IntNode *InsertNode(IntList *aList, IntNode *aNewNode, int anIndex);
IntNode *RemovedNode(IntList *aList, int anIndex);
void TheMinAndTheMax(IntNode *theList);


#endif

