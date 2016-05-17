//
//  main.c
//  Homework3
//
//  Created by Sergey Fedorenko on 7/4/16.
//  Copyright © 2016 Sergey Fedorenko. All rights reserved.
//

#include <stdio.h>
#include "Node.h"
#include "RingList.h"

int main(int argc, const char * argv[])
{
	int count=0;
	RingList *theList = doList();
	doPrintList(theList);
	printf("\n");
	
	printf("List after swapping Node\n");
	doPrintList(swapNodeAtList(theList));
	
	doSortingValue(theList);
	printf("\n");
	printf("List after sorting Node\n");
	doPrintList(theList);

	printf("Homework 3\n");
	//insertionSort(theList);
	//doPrintList(theList);
	insertionSort(theList, count);
	doPrintList(theList);
	system("pause");
}


void doPrintList(const RingList *aList)
{
	for (int i = 0; i<CountList(aList) ; i++)
	{
		IntNode *theNode = NodeAtIndex(aList, i);
		if (NULL != theNode)
		{
			printf("node[%d].value = %d\n", i, theNode->value);
		}
	}
}

