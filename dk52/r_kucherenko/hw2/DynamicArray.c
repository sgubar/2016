//
//  DynamicArray.c
//  doTest
//
//  Created by Slava Gubar on 3/24/16.
//  Copyright © 2016 Slava Gubar. All rights reserved.
//
#include <stdlib.h>
#include "DynamicArray.h"

DynamicIntArray *createDAInt(int aSize)
{
	DynamicIntArray* Massiv=malloc(sizeof(DynamicIntArray)); //create our box;
	Massiv->storage=malloc(sizeof(int)*aSize); // storage = pointer to mass;
	Massiv->physicalSize=aSize; // number of cells
	Massiv->logicalSize=0; // a new array - 0 employed;
	return Massiv;
}
void freeDAInt(DynamicIntArray *anArray)
{
	if(anArray!=NULL)
	{
	free(anArray->storage); //clear storrage;
	free(anArray); //and only after that clear our array;
	}
}
int valueAtIndex(DynamicIntArray *anArray, int anIndex)
{
	int value;
	if (anArray !=NULL)
	{
		if (anIndex < anArray -> physicalSize)
		{
		value=anArray->storage[anIndex]; //value of array record to storage;
		return value;
		}
	} 
    else
    {
		return NULL;
	
	// 	if there is a structure - to join the process
	}
void setValueAtIndex(DynamicIntArray *anArray, int anValue, int anIndex)
{
	if (anArray!=NULL)
	{
		if (anIndex < anArray ->physicalSize)
		{
			anArray->storage[anIndex]=anValue;// assigned value of a cell anVAlue;
			anArray->logicalSize++;//anArray->logicalSize=anArray->logicalSize+1;
		}
		else if (anIndex >= anArray -> physicalSize)
		{
			realloc(anArray->storage, anIndex*2);//size memory block that referenced parameter, change on 2 times;
			anArray -> physicalSize=anIndex*2*sizeof(int); //count cells*sine one;
			anArray -> storage[anIndex]=anValue;
			anArray->logicalSize++;
		}
	}   
	else
	{
	    anArray -> anDebg=0;// if false, 
	}
}
