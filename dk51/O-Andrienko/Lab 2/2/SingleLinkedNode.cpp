#include "SingleLinkedNode.h"
#include <stdlib.h>

IntNode *SLCreateNodeWithIntValue(int aValue, char aName)
{
	IntNode *theResult = (IntNode *)malloc(sizeof(IntNode));

	theResult->value = aValue;
	theResult->name = aName;
	theResult->nextNode = NULL;

	return theResult;
}

void SLFreeIntNode(IntNode *aNode)
{
	if (NULL != aNode)
	{
		free(aNode);
	}
}

char SLNodeName(IntNode *aNode)
{
	return aNode->name;
}