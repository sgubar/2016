//
//  main.c
//
//
//  Created by Bogdan Maximovich on 15/05/16.
//  Copyright © 2016 Bogdan Maximovich. All rights reserved.
//

#include <stdio.h>
#include "Node.h"
#include "list.h"
#include "DoubleList.h"

void doTestList();
void doPrintList(const IntList *aList);

int main()
{
	doTestList();
	return 0;
}

void doTestList()
{
	int CreateDoubleNode = 0;

	printf("List\n");
	printf("\n");

	IntNode *theNode1 = CreateNode(1);
	IntNode *theNode2 = CreateNode(4);
	IntNode *theNode3 = CreateNode(5);
	IntNode *theNode4 = CreateNode(3);
	IntNode *theNode5 = CreateNode(2);
	IntNode *theNode6 = CreateNode(9);
	IntNode *theNode7 = CreateNode(8);

	IntList *theList = CreateList();

	AddNode(theList, theNode1);
	AddNode(theList, theNode2);
	AddNode(theList, theNode3);
	AddNode(theList, theNode4);
	AddNode(theList, theNode5);
	AddNode(theList, theNode6);
	AddNode(theList, theNode7);

	doPrintList(theList);

    printf("\n");

	SortingNode(theList);

	doPrintList(theList);

	printf("\n\n");

	printf("Done.\n\n");

    FreeList(theList);

	system("pause");
}

void doPrintList(const IntList *aList)
{
	for (int i = 0; i < CountList(aList); i++)
	{
		IntNode *theNode = IndexNode(aList, i);
		if (NULL != theNode)
		{
			printf("node[%d].value = %d\n", i, theNode->value);
		}
	}
}
