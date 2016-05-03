
#ifndef SingleNODE_h
#define SingleNODE_h

#include <stdio.h>

typedef struct __MyNode MyNode;//predeclaration

struct __MyNode 
{
	char* value;//value of Node
	MyNode *nextNode;//reference to nextNode
};

MyNode *CreateNewNode(char value);//create a new node with value
void FreeNode(MyNode *Node);// free a creat node

#endif 