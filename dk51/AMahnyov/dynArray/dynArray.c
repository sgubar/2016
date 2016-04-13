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

subArray *addSub(dynamicArray *anArray, subArray *aSub){ //adding subarrays to arrays just like adding nodes to the list
    if(NULL == anArray || NULL == aSub){
        return NULL;
    }
    if(anArray->arrSize == 0){
        anArray->firstSub = aSub;
    }else{
        subArray *theLastSub = anArray->lastSub;
        anArray->lastSub = aSub;

        if(NULL != theLastSub){
            theLastSub->nextArray = aSub;
        }
    }
    anArray->arrSize++;
    printf("Added a subarray, current array size: %d\n", anArray->arrSize);
    return aSub;
}

void writeToDA(dynamicArray *anArray, int index, int value){
    if(index < getNumOfCells(anArray->arrSize)){ //inside bounds. This does not work
        printf("Writing inside bounds\n");
        int subNumber = 0;
        while(getFirstCellNumber(subNumber)<index){
            subNumber++; //define the number of a subarray in which there is a cell of a given index
        }
        subArray *currentSub = anArray->firstSub;
        for(int i = 0; i<subNumber; i++){
            currentSub = currentSub->nextArray; //navigate through array
        }
        currentSub->storage[index-getFirstCellNumber(subNumber)] = value;
    } else { //Outside bounds
        //works the same way as the inside writing...
        printf("Writing outside bounds\n");
        int subNumber = 0;
        while(getFirstCellNumber(subNumber)<index){
            subNumber++;
        }
        int i = subNumber;
        do{ //...but with adding more subarrays (like a vector array)
            subArray *subToAdd = createSubArray(pow(2, i));
            addSub(anArray, subToAdd);
            i++;
        }while(anArray->arrSize<subNumber);
        subArray *currentSub = anArray->firstSub;
        for(int i = 0; i<subNumber; i++){
            currentSub = currentSub->nextArray;
        }
        currentSub->storage[index-getFirstCellNumber(subNumber)] = value; //<-This does not work
    }
}
//should return the number of cells in a subbarray of a given number
static int getNumOfCells(int z){
    int a = 0;
    z--;
    for(int i = 0; i<z; i++){
        a = a*2+2;
    }
    return a;
}
//should return the index of the first cell in a subbarray of a given number
static int getFirstCellNumber(int z){
    int a = 0;
    for(int i = 0; i<z; i++){
        a = a*2+1;
    }
    return a;
}

int readFromDA(dynamicArray *anArray, int index){
    //if(index < getNumOfCells(anArray->arrSize)){ //<-This does not work
       int subNumber = 0;
       while(getFirstCellNumber(subNumber)<index){
           subNumber++;
       }
       subArray *currentSub = anArray->firstSub;
       for(int i = 0; i<subNumber; i++){
           currentSub = currentSub->nextArray;
       }
       return(currentSub->storage[index-getFirstCellNumber(subNumber)]);
    //}
return NULL;
}
