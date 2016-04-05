//
//  Node.c
//  demoList
//
//  Created by Sergey Fedorenko on 3/2/16.
//  Copyright © 2016 Slava Gubar. All rights reserved.
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
