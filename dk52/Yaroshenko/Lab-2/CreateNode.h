#ifndef CreateNode_h
#define CreateNode_h

#include <stdio.h>

//opisivaem noviy tip dannih "Node"

typedef struct Node Node;

struct Node{
	char symbol;
	Node *next;
};

Node *CreateNode(char symbol);

#endif 
