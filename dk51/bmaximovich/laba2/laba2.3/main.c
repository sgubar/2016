//
//  main.c
//
//
//  Created by Bogdan Maximovich on 23/03/16.
//  Copyright © 2016 Bogdan Maximovich. All rights reserved.
//

#include <stdio.h>
#include "Node.h"
#include "list.h"
#include "DoubleList.h"

void doTestList();
void doPrintList(const IntList *aList);

int main(int argc, const char * argv[])
{
	doTestList();
	return 0;
}

void doTestList()
{
	printf("List\n");
	printf("\n");
	IntNode *theNode1 = CreateNode(1);
	IntNode *theNode2 = CreateNode(2);
	IntNode *theNode3 = CreateNode(3);
	IntNode *theNode4 = CreateNode(4);
	IntNode *theNode5 = CreateNode(5);
	IntNode *theNode6 = CreateNode(6);
	IntNode *theNode7 = CreateNode(7);
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
	printf("Swapping\n");
	printf("\n");
	doPrintList(swapNodeAtList(theList));
    printf("\n");
	printf("doubleList\n");
	printf("\n");



	CreateDoubleList(theList, 10);
	doPrintList(theList);
	FreeList(theList);

	printf("\n");
	printf("Done.\n");
	printf("\n");

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
