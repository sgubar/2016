//
//  Simplesort.c
//  
//
//  Created by Serj Timoshenko on 4/18/16.
//  Copyright © 2016 Serj Timoshenko. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>



void bubbleSort(int anArray[], int aSize)// BUBBLE SORT
{
	for (int theOut = aSize - 1; theOut > 1; theOut--)
	{
		for (int theIn = 0; theIn < theOut; theIn++)
		{
			if (anArray[theIn] > anArray[theIn + 1])
			{
				int theTmp = anArray[theIn];
				anArray[theIn] = anArray[theIn + 1];
				anArray[theIn + 1] = theTmp;
			}
		}
	}
}
void selectionSort(int anArray[], int aSize)// SELECTION SORT
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
void insertionSort(int anArray[], int aSize)// INSERTION SORT
{
	for (int theOut = 1; theOut < aSize; theOut++)
	{
		int theTmp = anArray[theOut];
		int theIn = theOut;

		while (theIn > 0 && anArray[theIn - 1] >= theTmp)
		{
			anArray[theIn] = anArray[theIn - 1];
			--theIn;
		}

		anArray[theIn] = theTmp;
	}
}