//
//  Lab2
// 
//
//  Created by Nazar Bronnikov on 09/05/16.
//  Copyright (C) 2016 Nazar Bronnikov. All rights reserved.
//


#ifndef List_h
#define List_h
#include <stdio.h>
#include "Node.h"
//typedef struct __IntNode IntNode;
typedef struct __List
{
	IntNode *head;
	IntNode *tail;
	int count;
}List;

IntNode *AddNode(List *aList, IntNode *aNewNode);
#endif /*List_h*/
