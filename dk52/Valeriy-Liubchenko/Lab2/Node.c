
#include "Node.h"
#include<stdio.h>
#include<stdlib.h>


Node* CreateNode(int aValue)
{
    Node* CreatedNode=(Node*)malloc(sizeof(Node));
    CreatedNode->value=aValue;
    CreatedNode->nextptr=NULL;
    return CreatedNode;
}

void SLFreeNode(Node *aNode)
{
	if (NULL != aNode)
	{
		free(aNode);
	}
}
