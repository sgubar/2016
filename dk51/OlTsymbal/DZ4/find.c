//
//  find.c
//  demoFind
//

#include "find.h"
#include <limits.h>

const unsigned kNotFound = INT_MAX;

unsigned line_find(int anArray[], int aSize, int aKey)
{
	unsigned theResult = kNotFound;
	
	for (unsigned i = 0; i < aSize; i++)
	{
		if (anArray[i] == aKey)
		{
			theResult = i;
			break;
		}
	}
	
	return theResult;
}

void PrintArray(int anArray[], int aSize)
{
	for (int i = 0; i < aSize; i++)
	{
		printf("{");
		printf("%d", anArray[i]);
		printf("}");
	}
}

