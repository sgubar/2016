//
//  Node.h
//  Lab2
//
//  Created by Sergey Fedorenko on 3/23/16.
//  Copyright © 2016 Sergey Fedorenko. All rights reserved.
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

//Create a new Node with int value
IntNode *CreateNode(int aValue);
//Free a created node
void FreeNode(IntNode *aNode);

#endif /* Node_h */
