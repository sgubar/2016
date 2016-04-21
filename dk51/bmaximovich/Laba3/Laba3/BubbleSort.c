//
//  BubbleSort.c
//  
//
//  Created by Bogdan Maximovich on 4/21/16.
//  Copyright © 2016 Bogdan Maximovich. All rights reserved.
//

#include "BubbleSort.h"

void BubbleSort(int anArray[], int aSize)
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