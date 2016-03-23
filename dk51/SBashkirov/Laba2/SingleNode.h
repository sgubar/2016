//
//  SingleNode.h
//  Laba 2
//
//  Created by Stanislav Bashkirov on 3/21/16.
//  Copyright © 2016 Stanislav Bashkirov. All rights reserved.
//

#ifndef SingleNode_h
#define SingleNode_h

#include <stdio.h>

typedef struct __IntNode IntNode;

struct __IntNode
{
	int value;
	IntNode *nextNode;
};

IntNode *CreateNodeWithValue(int aValue);
void FreeNode(IntNode *aNode);

#endif 