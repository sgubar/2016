//
//  DynamicArray.c
//  doTest
//
//  Created by Serj Timoshenko on 5/219/16.
//  Copyright © 2016 Serj Timoshenko. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include "DynamicArray.h"



DynamicIntArray *createDAInt(int aSize)
{
	DynamicIntArray *DAr = (DynamicIntArray *)malloc(sizeof(DynamicIntArray));
	DAr->physicalSize = aSize;
	DAr->logicalSize = 0;
	DAr->storage = (int *)malloc(aSize*sizeof(int));
	for (int Elem = 0; Elem < aSize; Elem++)
		DAr->storage[Elem] = 0;
	return DAr;

}


void freeDAInt(DynamicIntArray *anArray)
{
	free(anArray->storage);
	free(anArray);

}




int valueAtIndex(DynamicIntArray *anArray, int anIndex, int theValue)
{


	if (anIndex > anArray->physicalSize)
	{

		int aSize = anArray->physicalSize;
		anArray->storage = (int *)realloc(anArray->storage, anIndex * sizeof(int) * 2);
		anArray->physicalSize = anIndex * 2;
		for (int Elem = 0; Elem <= aSize; Elem++)

		
		for (int Elem = aSize; Elem < anArray->physicalSize; Elem++)
			anArray->storage[Elem] = 0;
		anArray->storage[anIndex] = theValue;
		anArray->logicalSize++;
	}
	else
	{
		anArray->storage[anIndex] = theValue;
		anArray->logicalSize += 1;
	}


}
