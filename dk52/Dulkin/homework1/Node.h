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
IntNode *CreateNode(int aValue);
//Free a created node
void SetFreeNode(IntNode *aNode);

#endif /* SingleLinkedNode_h */
