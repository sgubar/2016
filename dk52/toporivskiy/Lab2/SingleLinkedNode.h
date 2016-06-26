//
//  SingleLinkedNode.h
//  Lab2
//
//  Created by Andrew Toporivskiy on 6/26/16.
//  Copyright © 2016 Andrew Toporivskiy. All rights reserved.
//

#ifndef SingleLinkedNode_h
#define SingleLinkedNode_h

#include <stdio.h>

// Predeclaration
typedef struct __IntNode IntNode;

// The node declaration
struct __IntNode
{
	int value;
	IntNode *nextNode;	//<! - the reference to next node
};

#endif /* SingleLinkedNode_h */