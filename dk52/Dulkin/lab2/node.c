#include "node.h"
#include <stdlib.h>

FloatNode *CreateNode(int aValue)
{
	FloatNode *theResult = (FloatNode *)malloc(sizeof(FloatNode));

	theResult->value = aValue;
	theResult->nextNode = NULL;

	return theResult;
}

void FreeNode(FloatNode *aNode)
{
	if (NULL != aNode)
	{
		free(aNode);
	}
};

