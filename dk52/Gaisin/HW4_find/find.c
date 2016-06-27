#include "find.h"
#include <limits.h>

const unsigned kNotFound = INT_MAX;

unsigned line_find(int anArray[], int aSize, int aKey) //function returned unsigned namber
{
	unsigned theResult = kNotFound;
	
	for (unsigned i = 0; i < aSize; i++) //that would work cycle aSize fold
	{
		if (anArray[i] == aKey) // if value equally aKey, then carry
		{
			theResult = i; //assign theResult namber
			break;
		}
	}
	
	return theResult;
}
