//
//  find.c
//  demoFind
//
//  Created by Slava Gubar on 5/10/16.
//  Copyright © 2016 Slava Gubar. All rights reserved.
//

#include "find.h"

const unsigned kNotFound = -1;

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


unsigned bi_find(int anArray[], int aSize, int aKey)
{
	unsigned theResult = kNotFound;
	unsigned theLowerBound = 0;
	unsigned theUpperBound = aSize - 1;
	unsigned theCurIn = 0;
	
	while (1)
	{
		theCurIn = (theLowerBound + theUpperBound) / 2;
		if (anArray[theCurIn] == aKey) //<!- an element was found
		{
			theResult = theCurIn;
			break;
		}
		else if (theLowerBound > theUpperBound) //<!- all elements were viewed
		{
			break;
		}
		else
		{
			if (anArray[theCurIn] < aKey)
			{
				theLowerBound = theCurIn + 1; //!<- in upper position
			}
			else
			{
				theUpperBound = theCurIn - 1; //!<- in lower position
			}
		}
	
	}
	
	return theResult;
}
