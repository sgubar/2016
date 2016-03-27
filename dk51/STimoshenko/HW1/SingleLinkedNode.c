//
//  SingleLinkedNode.c
// HomeWork
//
//  Created by Timoshenko Serj on 3/27/16.
//  Copyright © 2016 Timoshenko Serj . All rights reserved.
//
#include "SingleLinkedNode.h"
#include <stdlib.h>

IntNode *SLCreateNodeWithIntValue(int aValue)
{
	IntNode *theResult = (IntNode *)malloc(sizeof(IntNode));

	theResult->value = aValue;
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
