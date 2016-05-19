//
//  List.h
//  Lab2
//
//  Created by Ivan Romanenko on 19/4/16.
//  Copyright � 2016 Ivan Romanenko. All rights reserved.
//
#ifndef List_h
#define List_h
#include <stdio.h>
#include "Node.h"
//typedef struct __IntNode IntNode;
typedef struct __List
{
	IntNode *head;
	IntNode *tail;
	int count;
}List;

IntNode *AddNode(List *aList, IntNode *aNewNode);
#endif /*List_h*/