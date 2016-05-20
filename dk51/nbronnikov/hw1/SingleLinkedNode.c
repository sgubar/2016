//
//  hw1
// 
//
//  Created by Nazar Bronnikov on 09/05/16.
//  Copyright (C) 2016 Nazar Bronnikov. All rights reserved.
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
