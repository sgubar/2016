#ifndef NewNode_h
#define NewNode_h

#include <stdio.h>

typedef struct Node Node;

struct Node{
	int number;
	Node *next;
};

Node *CreateNode(int number);

#endif 
