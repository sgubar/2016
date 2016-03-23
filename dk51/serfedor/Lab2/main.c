//
//  main.c
//  Lab2
//
//  Created by Sergey Fedorenko on 3/23/16.
//  Copyright © 2016 Sergey Fedorenko. All rights reserved.
//

#include <stdio.h>
#include "Node.h"
#include "List.h"

void doList();
void doPrintList(const IntList *aList);

int main(int argc, const char * argv[])
{
	doList();

	return 0;
}

void doList()
{
	printf("Start to a circular list ...\n");

	IntNode *theNode0 = CreateNodeWithIntValue(0);
	IntNode *theNode1 = CreateNodeWithIntValue(4);
	IntNode *theNode2 = CreateNodeWithIntValue(3);
	IntNode *theNode3 = CreateNodeWithIntValue(5);
	IntNode *theNode4 = CreateNodeWithIntValue(1);
	IntNode *theNode5 = CreateNodeWithIntValue(2);

	IntList *theList = CreateList();
	printf("number of elements: %d\n", CountList(theList));

	AddNode(theList, theNode0);
	printf("number of elements: %d\n", CountList(theList));

	AddNode(theList, theNode1);
	printf("number of elements: %d\n", CountList(theList));

	AddNode(theList, theNode2);
	printf("number of elements: %d\n", CountList(theList));

    AddNode(theList, theNode3);
	printf("number of elements: %d\n", CountList(theList));

    AddNode(theList, theNode4);
	printf("number of elements: %d\n", CountList(theList));

	AddNode(theList, theNode5);
	printf("number of elements: %d\n", CountList(theList));

	InsertNodeAtIndex(theList, theNode0, 0);

	printf("number of elements: %d\n", CountList(theList));

	doPrintList(theList);

	FreeList(theList);

	printf("Done.\n");
}

void doPrintList(const IntList *aList)
{
	for (int i = 0; i < CountList(aList); i++)
	{
		IntNode *theNode = NodeAtIndex(aList, i);
		if (NULL != theNode)
		{
			printf("node[%d].value = %d\n", i, theNode->value);
		}
	}
}
