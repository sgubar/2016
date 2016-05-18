//
//  SingleNODE.c
//  List Laba2
//
//  Created by Tsymbal Olexandr on 19/05/16.
//  Copyright © 2016 OlTsymbal. All rights reserved.
//
#include "SingleNODE.h"
#include "function.h"
//#include <string.h>
#include <stdlib.h>
#include <malloc.h>

MyNode *CreateNewNode(char *aValue)
{
	int len = strlen(aValue);

	MyNode *theResult;
	theResult = (MyNode *)malloc(sizeof(MyNode));//reserv memory for our new node with value which contain some number of elements
	
	char * value;
	value = malloc((len + 1)*sizeof(char));//reserv memory for value which contain some number of elements
	memset(value, 0, len + 1);

	for (int i = 0; i < len ; i++)
	{
		value[i] = *(aValue + i);//write value
	}
	theResult->value = value;//value of Node= value
	theResult->nextNode = NULL;
	return theResult;
}
void FreeMyNode(MyNode *Node)
{
	if (NULL != Node)
	{
		free(Node);
	}
}
