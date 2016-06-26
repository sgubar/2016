//
//  Lab2
// 
//
//  Created by Nazar Bronnikov on 09/05/16.
//  Copyright (C) 2016 Nazar Bronnikov. All rights reserved.
//
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
