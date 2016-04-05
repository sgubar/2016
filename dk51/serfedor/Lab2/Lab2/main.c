//
//  main.c
//  Lab2
//
//  Created by Sergey Fedorenko on 3/23/16.
//  Copyright © 2016 Sergey Fedorenko. All rights reserved.
//

#include <stdio.h>
#include "Node.h"
#include "RingList.h"

//void doRingList();
//void doPrintList(const RingList *aList);

int main(int argc, const char * argv[])
{
	RingList *theList = doList();
	doPrintList(theList);
	printf("\n");
	MinMax(theList);
	printf("\n");
	doPrintList(theList);
	int IndexMaximum;
	int IndexMinimum;
	doSortingValue(theList, IndexMinimum, IndexMaximum);
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

