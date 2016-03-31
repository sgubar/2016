#include "node.h"
#include <stdlib.h>

IntNode *CreateNode(int aValue)
{
	IntNode *theResult = (IntNode *)malloc(sizeof(IntNode));

	theResult->value = aValue;
	theResult->nextNode = NULL;

	return theResult;
}

void FreeNode(IntNode *aNode)
{
	if (NULL != aNode)
	{
		free(aNode);
	}
};

