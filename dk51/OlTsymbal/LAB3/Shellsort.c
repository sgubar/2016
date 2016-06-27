#include"Sorting.h"

#include<stdio.h>
#include<time.h>

void shellSort(int anArray[], int aCount)
{
	clock_t start4, end4;
	int theInner = 0;
	int theOuter = 0;
	int theH = 1; // start h = 1

				  //1. Calculate start value of h
	while (theH <= aCount / 3)
	{
		theH = theH * 3 + 1; // 1, 4, 13, 40, 121, ....
	}


	start4 = clock();
	//2. Sequental decrease h to 1
	while (theH > 0)
	{
		for (theOuter = theH; theOuter < aCount; theOuter++)
		{
			int theTmp = anArray[theOuter];
			theInner = theOuter;

			// the first sub-array {0, 4, 8}
			while (theInner > theH - 1 && anArray[theInner - theH] >= theTmp)
			{
				anArray[theInner] = anArray[theInner - theH];
				theInner -= theH;
			}

			anArray[theInner] = theTmp;
		}

		theH = (theH - 1) / 3; //decrease h
	}
	end4 = clock();
	//printf("Time of start = %.15f", start4);
	//printf("Time of End = %.15f", end4);
	printf("Time of Shell sorting = %.15f\n", (double)(end4 - start4) / CLOCKS_PER_SEC);
}
