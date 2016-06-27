/* 
 * File:   node.c
 * Author: Ruslan Kucherenko
 *
 * Created on 1 червня 2016, 1:23
 * Compiled with gcc(cygwin)
 */

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
