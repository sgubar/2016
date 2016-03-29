//
//  SingleNode.h
//  Lab2
//
//  Created by Timoshenko Serj on 3/29/16.
//  Copyright (C) 2016 Timoshenko Serj. All rights reserved.
//


#pragma once
#ifndef SingleNode_h
#define SingleNode_h

#include <stdio.h>


typedef struct __IntNode IntNode;


struct __IntNode
{
	int value;
	char *CharWord;
	IntNode *nextNode;
};

IntNode *CreateNode(int aValue, char *CharWord);
void FreeIntNode(IntNode *aNode);

#endif