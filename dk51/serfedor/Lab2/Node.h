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

// Predeclaration
typedef struct __IntNode IntNode;

// The node declaration
struct __IntNode
{
	int value;
	IntNode *nextNode;//<! - the reference to next node
};

//Create a new Node with int value
IntNode *CreateNodeWithIntValue(int aValue);
//Free a created node
void FreeIntNode(IntNode *aNode);

#endif /* Node_h */
