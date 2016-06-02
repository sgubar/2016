#include "linear_find.h"
#include <limits.h>


unsigned linear_find(int anArray[], int aSize, int aKey)
{
	unsigned theResult = INT_MAX;

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
