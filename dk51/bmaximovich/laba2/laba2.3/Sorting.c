//
//  Sorting.c
//
//
//  Created by Bogdan Maximovich on 5/04/16.
//  Copyright © 2016 Bogdan Maximovich. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Node.h"
#include "List.h"
#include "DoubleList.h"
#include "Sorting.h"

IntList *SortingNode(IntList *theList)
{
	int a, min;
	int j = 0;
	int InMin = 0;
	int InMax = 0;
	int RemovedAtIndex = 0;
	a = CountList(theList);
	for (int j = 0; j < a; j++) {

		IntNode *TheMinNode = IndexNode(theList, InMin);
		min = IndexNode(theList, InMin)->value;

		for (int k = InMin; k < a; k++)
		{

			if (min <= TheMinNode->value)
			{
				min = TheMinNode->value;
				RemovedAtIndex = k;
			}

			TheMinNode = TheMinNode->nextNode;

		}

		InsertNodeAtIndex(theList, RemovedNodeAtIndex(theList, RemovedAtIndex), InMin);
		InMin++;

	}
	printf("Edited list\n");
	return theList;
}
