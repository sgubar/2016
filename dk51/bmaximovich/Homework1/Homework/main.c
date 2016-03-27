//
//  main.c
//  demoList
//
//  Created by Bogdan Maximovich on 23/03/16.
//  Copyright © 2016 Bogdan Maximovich. All rights reserved.
//

#include <stdio.h>
#include "SingleLinkedNode.h"
#include "SingleLinkedList.h"

void doTestSLList();
void doPrintSLList(const IntList *aList);

int main(int argc, const char * argv[])
{
	doTestSLList();

	return 0;
}

void doTestSLList()
{
	printf("Start to demo a single-linked list ...\n");
	
	IntNode *theNode2 = SLCreateNodeWithIntValue(2);
	IntNode *theNode4 = SLCreateNodeWithIntValue(4);
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	IntList *theList = SLCreateList();
	printf("number of elements: %d\n", SLCountList(theList));
////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	SLAddNode(theList, theNode2);
	printf("number of elements: %d\n", SLCountList(theList));

	SLAddNode(theList, theNode4);
	printf("number of elements: %d\n", SLCountList(theList));
	
	IntList *theList1 = createDoubleList(theList);
	printf("number of elements: %d\n", SLCountList(theList1));
	doPrintSLList(theList1);
	
	SLFreeList(theList);
	
	printf("Done.\n");
}

void doPrintSLList(IntList *aList)
{
	for (int i = 0; i < SLCountList(aList); i++)
	{
		IntNode *theNode = SLNodeAtIndex(aList, i);
		if (NULL != theNode)
		{
			printf("node[%d].value = %d\n", i, theNode->value);
		}
	}
	system("pause");
}
