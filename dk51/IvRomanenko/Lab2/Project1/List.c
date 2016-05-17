//
//  List.c
//  Lab2
//
//  Created by Ivan Romanenko on 19/4/16.
//  Copyright © 2016 Ivan Romanenko. All rights reserved.
//
#include "List.h"
#include "Node.h"
#include <stdlib.h>
List *CreateList()
{
	List *theList = (List *)malloc(sizeof(List));
	theList->head = NULL;
	theList->tail = NULL;
	return theList;

}
List *doList()
{
	printf("Create list\n");
	IntNode *theNode0 = CreateNode(1);
	IntNode *theNode1 = CreateNode(5);
	IntNode *theNode2 = CreateNode(14);
	IntNode *theNode3 = CreateNode(17);
	IntNode *theNode4 = CreateNode(4);
	List *theList = CreateList();
	AddNode(theList, theNode0);
	AddNode(theList, theNode1);
	AddNode(theList, theNode2);
	AddNode(theList, theNode3);
	AddNode(theList, theNode4);
	return(theList);

}
IntNode *AddNode(List *aList, IntNode *aNewNode)
{
	if (aList == NULL || aNewNode == NULL){
		return(NULL);
	}
	if ((NULL == aList->head) && (NULL == aList->tail))
		aList->head = aList->tail = aNewNode;
	else
	{
		IntNode *theTail = aList->tail;
		aList->tail = aNewNode;
		if (NULL != theTail)
			theTail->nextNode = aList->tail;
	}
	return aNewNode;
}
