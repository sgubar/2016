
//  node.c
//  linked list
//
//  Created by Masha Borodulya
//  Copyright © 2016 Masha Borodulya. All rights reserved.
//

#include "node.h"
#include <stdlib.h>

FloatNode *CreateFloatNode(float newValue)
{
    FloatNode *theNode = (FloatNode *)malloc(sizeof(FloatNode));
    theNode -> value = newValue;
    theNode -> nextNode = NULL;

    return theNode;
}

void FreeNode(FloatNode *tmp)
{
    if (NULL != tmp)
	{
		free(tmp);
	}

}
