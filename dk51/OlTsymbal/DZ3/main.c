//
//  main.c
//  List Laba2
//
//  Created by Tsymbal Olexandr on 19/05/16.
//  Copyright © 2016 OlTsymbal. All rights reserved.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "SingleLIST.h"
#include "SingleNODE.h"

void DoTestList();
void doPrintList(MyList *aList);

int main(int argc, char * argv[])
{
	DoTestList();

	return 0;
}

void DoTestList()
{
	printf("My list -->\n");
	MyNode *theNode1 = CreateNewNode("aaaaa");
	MyNode *theNode2 = CreateNewNode("bbbb");
	MyNode *theNode3 = CreateNewNode("Ccccccc");
	MyNode *theNode4 = CreateNewNode("dddddddd");
	MyNode *theNode5 = CreateNewNode("ee");
	MyNode *theNode6 = CreateNewNode("iii");

	MyList *aList = CreateANewList();

	AddNode(aList, theNode1);

	AddNode(aList, theNode2);

	AddNode(aList, theNode3);

	AddNode(aList, theNode4);

	printf("start number of elements: %d\n", ListCounter(aList));
	printf("My list without insertion\n");
	doPrintList(aList);
	printf("\n");

	InsertNode(aList, theNode5, 4);
	InsertNode(aList, theNode6, 5);

	printf("My list with insertion\n\n");
	doPrintList(aList);
	printf("number of all elements with insertion: %d\n\n", ListCounter(aList));

	MyNode *minNode = FindMinNode(aList);
	printf("MinNode [%s]\n\n", minNode->value);

	MyNode *maxNode = FindMaxNode(aList);
	printf("MaxNode [%s]\n\n", maxNode->value);

	printf("List with swapping\n");
	SwapNodeInList(aList);
	doPrintList(aList);
	printf("\n");

	printf("Sorting\n\n");
	//SortingList(aList);
	SelectionSorting(aList);
	doPrintList(aList);
	printf("\n");



	DeletedNode(aList, 1);

	printf("My list with delete\n\n");
	doPrintList(aList);
	printf("number of elements with delete: %d\n\n", ListCounter(aList));

	printf("delete key\n");
	DeleteKey(aList, "H");

	doPrintList(aList);
	printf("\n");

	LatterCount(aList);

	FreeMyList(aList);

	printf("DONE!!!\n");
	system("pause");
}

void doPrintList(MyList *aList)
{
	for (int i = 0; i < ListCounter(aList); i++)
	{
		MyNode *theNode = NodeAtIndex(aList, i);
		if (NULL != theNode)
		{
			printf("Node[%d] - value[%s]\n", i, theNode->value);
		}
	}
}