//
//  InsertionSort.c
//  
//
//  Created by Bogdan Maximovich on 4/21/16.
//  Copyright © 2016 Bogdan Maximovich. All rights reserved.
//

#include "InsertionSort.h"

void InsertionSort(int anArray[], int aSize)
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