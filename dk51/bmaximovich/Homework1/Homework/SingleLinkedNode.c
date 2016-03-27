//
//  SingleLinkedNode.c
//  demoList
//
//  Created by Bogdan Maximovich on 23/03/16.
//  Copyright © 2016 Bogdan Maximovich. All rights reserved.
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
