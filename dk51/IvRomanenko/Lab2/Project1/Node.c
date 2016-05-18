//
//  Node.c
//  Lab2
//
//  Created by Ivan Romanenko on 19/4/16.
//  Copyright © 2016 Ivan Romanenko. All rights reserved.
//
#include <stdlib.h>
#include "Node.h"

IntNode *CreateNode(int aValue){
	IntNode *Result = (IntNode *)malloc(sizeof(IntNode));
	Result->value = aValue;
	Result->nextNode = NULL;
	return(Result);
}
void FreeNode(IntNode *aNode){
	if (aNode != NULL)
		free(aNode);
}
