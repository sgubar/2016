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

void UnsortPrint(int anArray[], int aSize) {
	int i = 0;
	while (i<aSize + 1) {
		printf("%d, ", anArray[i]);
		i++;
	}
}
