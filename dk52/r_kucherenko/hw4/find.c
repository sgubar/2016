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

int RecursiveBinarySearch(int* array,int left,int right,int value)
{
    int center=(left+right)/2;
    if(array!=NULL&&left<right)
    {
        if(array[center]==value) return center;
    
    else if(array[center]<value)//in the right part
        RecursiveBinarySearch(array,center+1,right,value);
    
    else if(array[center]>value)//in the left part
        RecursiveBinarySearch(array,left,center-1,value);
    }
    else return NULL;
}