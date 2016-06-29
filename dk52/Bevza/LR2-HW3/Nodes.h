#ifndef Nodes_h
#define Nodes_h
#include <stdio.h>
#include<stdlib.h>

typedef struct Node Node;
struct Node
{
    int value;
    Node* next;/*pointer on next node*/
};

Node* CreateNode(int value);

void FreeNode(Node *aNode);

doubleNode* CreateDNode (char aString)
#endif

