//
//  find.c
//  demoFind
//
//  Created by Slava Gubar on 5/10/16.
//  Copyright © 2016 Slava Gubar. All rights reserved.
//

#include "LineFind.h"

const unsigned kNotFound = -1;

unsigned linefind(int anArray[], int aSize, int aKey)
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
	system("pause");
}