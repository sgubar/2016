//
//  hw1
// 
//
//  Created by Nazar Bronnikov on 09/05/16.
//  Copyright (C) 2016 Nazar Bronnikov. All rights reserved.
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
	
	IntList *theList = SLCreateList();
	printf("number of elements: %d\n", SLCountList(theList));
	
	SLAddNode(theList, theNode2);
	printf("number of elements: %d\n", SLCountList(theList));

	SLAddNode(theList, theNode4);
	printf("number of elements: %d\n", SLCountList(theList));
	
	doPrintSLList(theList);
	printf("\n \n");

	IntNode *theNode42 = SLCreateNodeWithIntValue(42);
	SLInsertNodeAtIndex(theList, theNode42, 1);

	IntNode *theNode1 = SLCreateNodeWithIntValue(1);
	SLInsertNodeAtIndex(theList, theNode1, 0);

	doPrintSLList(theList);
	printf("\n \n");

	SLRemovedNodeAtIndex(theList, 0);

	doPrintSLList(theList);
	printf("\n \n");

	SLFreeList(theList);
	
	printf("Done.\n");

	int buster;
	scanf_s("%d\n", &buster);
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
