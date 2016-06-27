//
//  Lab2
// 
//
//  Created by Nazar Bronnikov on 09/05/16.
//  Copyright (C) 2016 Nazar Bronnikov. All rights reserved.
//

#ifndef Node_h
#define Node_h
#include <stdio.h>
typedef struct __IntNode IntNode;
struct __IntNode
{
	int value;
	IntNode *nextNode;
};

IntNode *CreateNode(int aValue);

#endif /*Node_h*/
