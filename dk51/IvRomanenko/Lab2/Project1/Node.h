//
//  Node.h
//  Lab2
//
//  Created by Ivan Romanenko on 19/4/16.
//  Copyright � 2016 Ivan Romanenko. All rights reserved.
//
#ifndef Node_h
#define Node_h
#include <stdio.h>
typedef struct __IntNode IntNode;
struct __IntNode
{
	int value;
	IntNode *nextNode;
};

IntNode *CreateNode(int aValue);

#endif /*Node_h*/