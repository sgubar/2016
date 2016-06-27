//
//  bubbleSort.c
//  Lab2
//
//  Created by Andrew Toporivskiy on 6/26/16.
//  Copyright © 2016 Andrew Toporivskiy. All rights reserved.
//

#include "bubbleSort.h"
#include "SingleLinkedList.h"
#include "SingleLinkedNode.h"

void bubbleSort(IntList *aList)
{
	int sortingIndex = 0;
	for (int i = 0; i < CountList(aList); i++)
	{
		InsertNodeAtIndex(aList, RemovedNodeAtIndex(aList, i), sortingIndex);
		sortingIndex++;
	}
}