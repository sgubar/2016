//
//  SingleNode.c
//  Laba 2
//
//  Created by Stanislav Bashkirov on 3/21/16.
//  Copyright © 2016 Stanislav Bashkirov. All rights reserved.
//

#include "SingleNode.h"
#include <stdlib.h>

IntNode *CreateNodeWithValue(int aValue)
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
