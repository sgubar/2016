#ifndef SingleLinkedNode_h
#define SingleLinkedNode_h

#include <stdio.h>

// Predeclaration
typedef struct __IntNode IntNode;

// The node declaration
struct __IntNode
{
	int value;
	char name;
	IntNode *nextNode;//<! - the reference to next node
};

//Create a new Node with int value
IntNode *SLCreateNodeWithIntValue(int aValue, char aName);
//Free a created node
void SLFreeIntNode(IntNode *aNode);

char SLNodeName(IntNode *aNode);

#endif /* SingleLinkedNode_h */