//
//  SelectionSort.c
//  
//
//  Created by Bogdan Maximovich on 4/21/16.
//  Copyright © 2016 Bogdan Maximovich. All rights reserved.
//

#include "SelectionSort.h"

void SelectionSort(int anArray[], int aSize)
{
	for (int theOut = 0; theOut < aSize - 1; theOut++)
	{
		int theMinIndex = theOut;

		for (int theIn = theOut + 1; theIn < aSize; theIn++)
		{
			if (anArray[theIn] < anArray[theMinIndex])
			{
				theMinIndex = theIn;
			}
		}

		int theTmp = anArray[theOut];
		anArray[theOut] = anArray[theMinIndex];
		anArray[theMinIndex] = theTmp;
	}
}