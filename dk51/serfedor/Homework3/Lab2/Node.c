//
//  Node.c
//  Homework3
//
//  Created by Sergey Fedorenko on 4/7/16.
//  Copyright © 2016 Sergey Fedorenko. All rights reserved.
//

#include "Node.h"
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
}
