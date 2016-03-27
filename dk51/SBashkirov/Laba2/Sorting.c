//
//  Sorting.c
//  Laba 2
//
//  Created by Stanislav Bashkirov on 3/26/16.
//  Copyright © 2016 Stanislav Bashkirov. All rights reserved.
//

#include <stdio.h>
#include "SingleList.h"
#include "SingleNode.h"

int NodeSorting(IntList *aList, int Number, int FirstBorder, int SecondBorder)
{
	int sortingIndex = 0;
	for (int i=0; i < CountList(aList);i++)
	{
		if (NodeAtIndex(aList, i)->value < Number)
		{
			InsertNodeAtIndex(aList, RemovedNodeAtIndex(aList,i), sortingIndex);
			sortingIndex++;
		}
	}
	for (int i=0;i < CountList(aList);i++)
	{
		if ((NodeAtIndex(aList, i)->value >= FirstBorder) && (NodeAtIndex(aList,i)->value <= SecondBorder))
		{
			InsertNodeAtIndex(aList, RemovedNodeAtIndex(aList,i), sortingIndex);
			sortingIndex++;
		}
	}
}