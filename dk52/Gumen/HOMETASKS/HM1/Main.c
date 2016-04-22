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

int doTestSLList();
void doPrintSLList(const IntList *aList);

int main(int argc, const char * argv[])
{
	doTestSLList();

	return 0;
}

int doTestSLList()
{
	int indexTOinsert = 0, indexTOremove = 0;
	int NewNodeValue = 0;;
	printf("Start to demo a single-linked list ...\n");
	
	IntNode *theNode2 = SLCreateNodeWithIntValue(2);
	IntNode *theNode4 = SLCreateNodeWithIntValue(4);
	IntNode *theNode8 = SLCreateNodeWithIntValue(8);
	IntNode *theNode16 = SLCreateNodeWithIntValue(16);
	IntNode *theNode32 = SLCreateNodeWithIntValue(32);
	IntNode *theNode64 = SLCreateNodeWithIntValue(64);
	
	IntList *theList = SLCreateList();
	printf("number of elements: %d\n", SLCountList(theList));
	
	SLAddNode(theList, theNode2);
	printf("number of elements: %d\n", SLCountList(theList));

	SLAddNode(theList, theNode4);
	printf("number of elements: %d\n", SLCountList(theList));

	SLAddNode(theList, theNode8);
	printf("number of elements: %d\n", SLCountList(theList));

	SLAddNode(theList, theNode16);
	printf("number of elements: %d\n", SLCountList(theList));

	SLAddNode(theList, theNode32);
	printf("number of elements: %d\n", SLCountList(theList));

	SLAddNode(theList, theNode64);
	printf("number of elements: %d\n", SLCountList(theList));

	printf("Enter the value of the new node: ");
	scanf_s("%d", & NewNodeValue);

	IntNode *theNodeNew = SLCreateNodeWithIntValue(NewNodeValue);

	printf("At what index do you want to insert the node? ");
	scanf_s("%d", & indexTOinsert);

	SLInsertNodeAtIndex(theList, theNodeNew, indexTOinsert);
	printf("number of elements: %d\n", SLCountList(theList));

	doPrintSLList(theList);

	printf("Node at which index do you want to remove? \n");
	scanf_s("%d", &indexTOremove);

	SLRemovedNodeAtIndex(theList, indexTOremove);
	printf("number of elements: %d\n", SLCountList(theList));

	doPrintSLList(theList);
	

	
	printf("Done.\n");
	return 0;

}

void doPrintSLList(const IntList *aList)
{
	int i=0;
	for (; i < SLCountList(aList); i++)
	{
		IntNode *theNode = SLNodeAtIndex(aList, i);
		if (NULL != theNode)
		{
			printf("node[%d].value = %d\n", i, theNode->value);
		}
	}
}

