#include "Nodes.h"
#include<stdio.h>
#include<stdlib.h>


Node* CreateNode(int value);
{
    Node* CreatedNode=(Node*)malloc(sizeof(Node));
    CreatedNode->value=aValue;
    CreatedNode->next=NULL;
    return CreatedNode;
}

void FreeNode(Node *aNode)
{
	if (NULL != aNode)
	{
		free(aNode);
	}
}
