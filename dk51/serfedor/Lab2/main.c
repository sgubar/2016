//
//  main.c
//  Lab2
//
//  Created by Sergey Fedorenko on 3/23/16.
//  Copyright © 2016 Sergey Fedorenko. All rights reserved.
//

#include <stdio.h>
#include "Node.h"
#include "RingList.h"

void doRingList();
void doPrintList(const RingList *aList);

int main(int argc, const char * argv[])
{
	doList();

	return 0;
}

void doList()
{
	printf("Start to create a circular list \n");

	IntNode *theNode0 = CreateNode(0);
	IntNode *theNode1 = CreateNode(4);
	IntNode *theNode2 = CreateNode(3);
	IntNode *theNode4 = CreateNode(5);
	IntNode *theNode5 = CreateNode(1);
	IntNode *theNode6 = CreateNode(2);

	RingList *theList = CreateList();


	AddNode(theList, theNode0);

	AddNode(theList, theNode1);

	AddNode(theList, theNode2);

    AddNode(theList, theNode4);

    AddNode(theList, theNode5);

	AddNode(theList, theNode6);
	printf("number of elements: %d\n", CountList(theList));

	//NodeAtIndex(RingList,aList->count)->nextNode=aList->head;

	doPrintList(theList);

	FreeList(theList);


}

void doPrintList(const RingList *aList)
{
	for (int i = 0; i < CountList(aList) +5 ; i++)
	{
		IntNode *theNode = NodeAtIndex(aList, i);
		if (NULL != theNode)
		{
			printf("node[%d].value = %d\n", i, theNode->value);
		}
	}
}
