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
{	unsigned i = 0;
	unsigned theResult = kNotFound;
	
	for ( i = 0; i < aSize; i++)
	{
		if (anArray[i] == aKey)
		{
			theResult = i;
			break;
		}
	}
	
	return theResult;
}

void UnsortPrint (int anArray[], int aSize){
	int i=0;
	while(i<aSize+1){
		printf("%d, ",anArray[i]);
		i++;
	}
}
