//
//  main.c
//  demoList
//
//  Created by Slava Gubar on 3/1/16.
//  Copyright © 2016 Slava Gubar. All rights reserved.
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
	
	IntNode *theNode1 = SLCreateNodeWithIntValue(1);
	IntNode *theNode2 = SLCreateNodeWithIntValue(2);
	IntNode *theNode4 = SLCreateNodeWithIntValue(4);
	IntNode *theNode3 = SLCreateNodeWithIntValue(5);
	
	IntList *theList = SLCreateList();
	printf("number of elements: %d\n", SLCountList(theList));

	SLAddNode(theList, theNode1);
	printf("number of elements: %d\n", SLCountList(theList));
	
	SLAddNode(theList, theNode2);
	printf("number of elements: %d\n", SLCountList(theList));

	SLAddNode(theList, theNode4);
	printf("number of elements: %d\n", SLCountList(theList));
	
	printf("Mylist without insertion\n");
	doPrintSLList(theList);

	SLInsertNodeAtIndex(theList, theNode3, 1);
	printf("number of elements: %d\n", SLCountList(theList));
	
	printf("Mylist with insertion\n");
	doPrintSLList(theList);

	SLRemovedNodeAtIndex(theList, 2);

	printf("Remov theNode\n");

	doPrintSLList(theList);
	
	SLFreeList(theList);
	
	printf("Done.\n");
	system("pause");
}

void doPrintSLList(const IntList *aList)
{
	for (int i = 0; i < SLCountList(aList); i++)
	{
		IntNode *theNode = SLNodeAtIndex(aList, i);
		if (NULL != theNode)
		{
			printf("node[%d].value = %d\n", i, theNode->value);
		}
	}

}
