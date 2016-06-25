#include <stdio.h>

#include "sortArray.h"

int sortArray(int *arrayy, int Asize)
{
	int theOut;
	int theIn;
	for (theOut = Asize; theOut > 1; theOut --)
	{
		for (theIn = 0; theIn < theOut; theIn ++)
		{
			if (arrayy[theIn] > arrayy[theIn + 1])
			{
				int theTmp = arrayy[theIn];
				arrayy[theIn] = arrayy[theIn + 1];
				arrayy[theIn + 1] = theTmp;
			}
		}
	}
	return *arrayy;
}
