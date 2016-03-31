//  Fun.h
//  Laba. 2 var. 13
//
//  Created by Ryzhenkov Serhii on 30/03/16.
//  Copyright © 2016 Ryzhenkov Serhii. All rights reserved.

typedef struct __IntNode IntNode;
struct __IntNode
{
	int value;
	IntNode *nextNode;
};

IntNode *CreateNode(int converting);
void FreeIntNode(IntNode *Node);
void distribution(IntNode *theList);
//void UpdatedValue(IntNode *theList);
#pragma once
