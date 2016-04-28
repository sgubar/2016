//
//  quickSort.c
//  demoSimpleSort
//
//  Created by Slava Gubar on 4/27/16.
//  Copyright © 2016 Slava Gubar. All rights reserved.
//

#include "quickSort.h"

#if 1 //{
int partitionIt(int anArray[], int aLeftIndex, int aRightIndex, int aPivot)
{
	int theLeft = aLeftIndex - 1;
	int theRight = aRightIndex + 1;
	
	while (1)
	{
		// search the bigest element
		while (theLeft < aRightIndex && anArray[++theLeft] < aPivot);
	
		// search the lowest element
		while (theRight > aLeftIndex && anArray[--theRight] > aPivot);
	
		if (theLeft >= theRight) // pointer are the same 
		{
			break;
		}
		else
		{
			//lets to swap elements
			int theTmp = anArray[theLeft];
			anArray[theLeft] = anArray[theRight];
			anArray[theRight] = theTmp;
		}
	}
	
	return theLeft; // return break position
}

#else //}{

int partitionIt(int anArray[], int aLeftIndex, int aRightIndex, int aPivot)
{
	int theLeft = aLeftIndex - 1;
	int theRight = aRightIndex;
	
	while (1)
	{
		// search the bigest element
		while (anArray[++theLeft] < aPivot);
	
		// search the lowest element
		while (theRight > 0 && anArray[--theRight] > aPivot);
	
		if (theLeft >= theRight) // pointer are the same 
		{
			break;
		}
		else
		{
			//lets to swap elements
			int theTmp = anArray[theLeft];
			anArray[theLeft] = anArray[theRight];
			anArray[theRight] = theTmp;
		}
	}

	//lets to swap elements
	int theTmp = anArray[theLeft];
	anArray[theLeft] = anArray[aRightIndex];
	anArray[aRightIndex] = theTmp;
	
	return theLeft; // return break position
}
#endif

void quickSort(int anArray[], int aLeftIndex, int aRightIndex)
{
	if (aRightIndex - aLeftIndex <= 0)
	{
		return; // the array size equals to 1 - the array is fully sorted
	}
	
	int thePivot = anArray[aRightIndex];
	int thePartitionIndex = partitionIt(anArray, aLeftIndex, aRightIndex, thePivot);
	
	//left part sorting
	quickSort(anArray, aLeftIndex, thePartitionIndex - 1);
	
	//right part sorting
	quickSort(anArray, thePartitionIndex + 1, aRightIndex);
}