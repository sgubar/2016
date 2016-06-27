//
//  find.c
//  demoFind
//
//  Created by Slava Gubar on 5/10/16.
//  Copyright © 2016 Slava Gubar. All rights reserved.
//

#include "find.h"
#include <limits.h>

const unsigned kNotFound = INT_MAX;

unsigned line_find(int anArray[], int aSize, int aKey)
{
	unsigned theResult = kNotFound;
	unsigned i = 0;


	for (; i < aSize; i++)
	{
		if (anArray[i] == aKey)
		{
			theResult = i;
			break;
		}
	}

	//printf("result %d\n", theResult);
	return theResult;
	
}

void uoa_print(int anArray[], int aSize)
{
	printf("Printing unsorted array:\n");
	for (int i = 0; i < aSize; i++)
		printf("%d,", anArray[i]);
}
