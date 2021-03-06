//
//  main.c
//  HomeWork
//
//  Created by Timoshenko Serj on 3/27/16.
//  Copyright � 2016 Timoshenko Serj . All rights reserved.
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
	
	IntNode *theNode3 = SLCreateNodeWithIntValue(3);//Add a new node

	IntNode *theNode4 = SLCreateNodeWithIntValue(4);

	IntList *theList = SLCreateList();
	printf("number of elements: %d\n", SLCountList(theList));


	SLAddNode(theList, theNode2);
	printf("number of elements: %d\n", SLCountList(theList));

	SLAddNode(theList, theNode3);
	printf("number of elements: %d\n", SLCountList(theList));


	SLAddNode(theList, theNode4);
	printf("number of elements: %d\n", SLCountList(theList));
	
	doPrintSLList(theList);

	SLRemovedNodeAtIndex(theList, 1);//delete a new node
	printf("'theNode3' is deleted\n");

	doPrintSLList(theList);
	SLFreeList(theList);


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
	system("pause");
}