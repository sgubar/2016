
#include <stdio.h>
#include "list.h"
#include "node.h"

FloatList *Sorting(FloatList *aList, float Number, float FirstBorder, float SecondBorder)
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
	for (int i=sortingIndex;i < CountList(aList);i++)
	{
		if ((NodeAtIndex(aList, i)->value >= FirstBorder) && (NodeAtIndex(aList,i)->value <= SecondBorder))
		{
			InsertNodeAtIndex(aList, RemovedNodeAtIndex(aList,i), sortingIndex);
			sortingIndex++;
		}
	}
	return aList;
}
