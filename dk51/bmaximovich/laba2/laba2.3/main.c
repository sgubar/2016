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
	printf("List ...\n");

	IntNode *theNode2 = CreateNode(2);
	IntNode *theNode3 = CreateNode(3);
	IntNode *theNode4 = CreateNode(4);
	IntNode *theNode5 = CreateNode(5);
	IntNode *theNode6 = CreateNode(6);

	IntList *theList = CreateList();
	printf("number of elements: %d\n", CountList(theList));

	AddNode(theList, theNode2);
	printf("number of elements: %d\n", CountList(theList));
	AddNode(theList, theNode3);
	printf("number of elements: %d\n", CountList(theList));
	AddNode(theList, theNode4);
	printf("number of elements: %d\n", CountList(theList));
	AddNode(theList, theNode5);
	printf("number of elements: %d\n", CountList(theList));
	AddNode(theList, theNode6);
	printf("number of elements: %d\n", CountList(theList));

	IntList *theList1 = ÑreateDoubleList(theList);
	printf("number of elements at DoubleList: %d\n", CountList(theList1));

	doPrintList(theList1);

	FreeList(theList);

	printf("Done.\n");
}

void doPrintList(IntList *aList)
{
	for (int i = 0; i < CountList(aList); i++)
	{
		IntNode *theNode = IndexNode(aList, i);
		if (NULL != theNode)
		{
			printf("node[%d].value = %d\n", i, theNode->value);
		}
	}
	system("pause");
}
