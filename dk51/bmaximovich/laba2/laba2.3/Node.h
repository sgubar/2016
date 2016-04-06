#pragma once
//
//  Node.h
//
//
//  Created by Bogdan Maximovich on 23/03/16.
//  Copyright © 2016 Bogdan Maximovich. All rights reserved.
//

#ifndef Node
#define Node
#include <stdio.h>

typedef struct __IntNode IntNode;

struct __IntNode
{
	int value;
	IntNode *nextNode;  //reference to next node
};

//New Node with int value
IntNode *CreateNode(int aValue);

//Free a created node
void FreeNode(IntNode *aNode);

#endif /* Node */
