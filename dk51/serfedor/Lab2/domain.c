//
//  SingleNode.c
//  Lab 2
//
//  Created by Sergey Fedorenko on 3/21/16.
//  Copyright © 2016 Sergey Fedorenko. All rights reserved.
//

#include "SingleNode.h"
#include <stdlib.h>

IntNode *CreateNodeWithIntValue(int aValue)
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
