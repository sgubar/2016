#include <stdio.h>
#include<stdlib.h>
#include "doublenodes.h"

doubleNode* CreateDNode(char aLetter);
{
 doubleNode* CreatedNode=(doubleNode*)malloc(sizeof(doubleNode));
    CreatedDNode->letter=aLetter;
    prevnode->CreatedDNode=NULL;
    CreatedDNode->nextnode=NULL;
    return CreatedDNode;
}

void freeDNode(doubleNode *aDNode)
{
	if (NULL != aDNode)
	{
		free(aDNode);
	}
}


