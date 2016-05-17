//
//  Node.h
//  Homework3
//
//  Created by Sergey Fedorenko on 7/4/16.
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
	IntNode *prevNode;
};

//Create a new Node with int value
IntNode *CreateNode(int aValue);
//Free a created node
void FreeNode(IntNode *aNode);

#endif /* Node_h */
