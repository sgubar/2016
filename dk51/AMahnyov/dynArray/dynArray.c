/*Copyright (c), 2016, Mahnyov Aleksander. All rights reserved*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dynArray.h"

dynamicArray *createDynArray();
subArray *addSub(dynamicArray *anArray, subArray *aSub);
subArray *createSubArray(int aSize);
void writeToDA(dynamicArray *anArray, int index, int value);
int readFromDA(dynamicArray *anArray, int index);
void freeSubArray(subArray *anArray);
void freeDynArray(dynamicArray *anArray);
static int getNumOfCells(int z);
static int getFirstCellNumber(int z);

static int getNumOfAvailableCells(dynamicArray *anArray);
static void setValueAtIndex(dynamicArray *anArray, int anIndex, int aValue);
static void prepareArrayWithIndex(dynamicArray *anArray, int anIndex);

dynamicArray *createDynArray(){
    dynamicArray *theArray = (dynamicArray *)malloc(sizeof(dynamicArray));
    theArray->firstSub = NULL;
    theArray->lastSub = NULL;
    theArray->arrSize = 0;
    printf("Created dynArray\n\n");
    return theArray;
}

void freeDynArray(dynamicArray *anArray){
    if(NULL == anArray) return;
    subArray *aSub = anArray->firstSub;
    while(NULL != aSub){
        subArray *aSubToDelete = aSub;
        aSub = aSub->nextArray;
        free(aSubToDelete);
    }
    free(anArray);
}

subArray *createSubArray(int aSize){
    subArray *theSub = (subArray *)malloc(sizeof(subArray));
    int *aStorage = malloc(sizeof(int)*aSize);
    printf("Allocated %d bytes for subarray\n", (sizeof(int)*aSize));
    theSub->storage = aStorage;
    theSub->nextArray = NULL;
    theSub->subSize=aSize;
    return theSub;
}

void freeSubArray(subArray *anArray){
    if(NULL != anArray) free(anArray);
}

subArray *addSub(dynamicArray *anArray, subArray *aSub)
{ //adding subarrays to arrays just like adding nodes to the list
    if(NULL == anArray || NULL == aSub)
	 {
        return NULL;
    }

	 if(anArray->arrSize == 0)
	 {
        anArray->firstSub = anArray->lastSub = aSub;
    }
	 else
	 {
        anArray->lastSub->nextArray = aSub;
		  anArray->lastSub = aSub;
    }

    anArray->arrSize ++;

    printf("Added a subarray, current array size: %d\n", anArray->arrSize);
    return aSub;
}

void writeToDA(dynamicArray *anArray, int index, int value)
{
//    if(index < getNumOfCells(anArray->arrSize)){ //inside bounds. This does not work
	if (index < getNumOfAvailableCells(anArray))
	{
		printf("Writing inside bounds\n");
		setValueAtIndex(anArray, index, value);
    }
	 else
	 { //Outside bounds
		//works the same way as the inside writing...
		printf("Writing outside bounds\n");

		//create required additional subarrays
		prepareArrayWithIndex(anArray, index);
		setValueAtIndex(anArray, index, value);
    }
}

int readFromDA(dynamicArray *anArray, int index){
    if(index <= getNumOfAvailableCells(anArray)){
        subArray *theSlot = anArray->firstSub;
            while (NULL != theSlot)
            {
            if (index < theSlot->subSize)
            {
                return theSlot->storage[index];
            }
            index -= (theSlot->subSize - 1);
            theSlot = theSlot->nextArray;
            }
    }
	return NULL;
}

#pragma mark -
int getNumOfAvailableCells(dynamicArray *anArray)
{
	int theResult = 0;

	if (anArray->arrSize > 0)
	{
		subArray *theSubArray = anArray->firstSub;
		while (NULL != theSubArray)
		{
			theResult += theSubArray->subSize;
			theSubArray = theSubArray->nextArray;
		}
	}

	return theResult;
}

subArray *getRequiredSlotForIndex(dynamicArray *anArray, int *ioOffset)
{
	int index = *ioOffset;
	subArray *theSlot = anArray->firstSub;
	while (NULL != theSlot)
	{
		if (index < theSlot->subSize)
		{
			break;
		}

		index -= (theSlot->subSize - 1);
		theSlot = theSlot->nextArray;
	}

	*ioOffset = index;

	return theSlot;
}

void setValueAtIndex(dynamicArray *anArray, int anIndex, int aValue)
{
	subArray *theSlot = anArray->firstSub;
	while (NULL != theSlot)
	{
		if (anIndex < theSlot->subSize)
		{
			theSlot->storage[anIndex] = aValue;
			break;
		}

		anIndex -= (theSlot->subSize - 1);
		theSlot = theSlot->nextArray;
	}
}

void prepareArrayWithIndex(dynamicArray *anArray, int anIndex)
{
	while (anIndex >= 0)
	{
		//calculate a size
		int theSize = 10; //<!-- by default

		if (NULL != anArray->lastSub)
		{
			theSize = anArray->lastSub->subSize * 2;
		}

		subArray *theSlot = createSubArray(theSize);
		addSub(anArray, theSlot);

		anIndex -= theSize;
	}
}
