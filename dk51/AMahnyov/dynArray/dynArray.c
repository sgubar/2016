/*Copyright (c), 2016, Mahnyov Aleksander. All rights reserved*/
#include <stdio.h>
#include <stdlib.h>
#include "dynArray.h"

dynamicArray *createDynArray(int aSize);
subArray *addSub(dynamicArray *anArray, subArray *aSub);
subArray *createSubArray(int aSize);
void writeToDA(dynamicArray *anArray, int index, int value);
int readFromDA(dynamicArray *anArrat, int index);

dynamicArray *createDynArray(int aSize){
    dynamicArray *theArray = (dynamicArray *)malloc(sizeof(dynamicArray));

    for(int i = 0; i<aSize; i++){
        subArray *subToAdd = createSubArray(2^i);
        addSub(theArray, subToAdd);
    }

    return theArray;
}

subArray *createSubArray(int aSize){
    subArray *theSub = (subArray *)malloc(sizeof(subArray));
    int *aStorage = malloc(sizeof(int)*aSize);
    theSub->storage = aStorage;
    theSub->nextArray = NULL;
    theSub->subSize=aSize;
    return theSub;
}

subArray *addSub(dynamicArray *anArray, subArray *aSub){
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
    return aSub;
}

void writeToDA(dynamicArray *anArray, int index, int value){
    if(NULL != anArray){
        if(index > 0 || index <= (2^(anArray->arrSize))){
            int numOfSub = 0;
            while(index<numOfSub){
                numOfSub = 2^numOfSub;
            }
            subArray *currentSub = anArray->firstSub;
            for(int i = 0; i<numOfSub; i++){
                currentSub=currentSub->nextArray;
            }
            int *aStorage = currentSub->storage;
            int indexInSub = index-(2^numOfSub);
            aStorage[indexInSub] = value;
        }else{
            subArray *subToAdd = createSubArray((anArray->arrSize)^2);
            addSub(anArray, subToAdd);
        }
    }
}

int readFromDA(dynamicArray *anArray, int index){
    int numOfSub = 0;
    while(index<numOfSub){
        numOfSub = 2^numOfSub;
    }
    subArray *currentSub = anArray->firstSub;
    for(int i = 0; i<numOfSub; i++){
        currentSub=currentSub->nextArray;
    }
    int *aStorage = currentSub->storage;
    int indexInSub = index-(2^numOfSub);
    return (aStorage[indexInSub]);
}
