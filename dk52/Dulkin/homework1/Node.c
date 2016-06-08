#include "Node.h"
#include <stdlib.h>

IntNode *CreateNode(int aValue)
{
	IntNode *theResult = (IntNode *)malloc(sizeof(IntNode));
	
	theResult->value = aValue;
	theResult->nextNode = NULL;
	
	return theResult;
}

void SetFreeNode(IntNode *aNode)
{
	if (NULL != aNode)
	{
		free(aNode);
	}
}
