#include <stdio.h>
#include <stdlib.h>
#include "searchFunctions.h"

int searchIn(int anArray[], int leftBound, int rightBound, int key);
int *generateOrdArray(int size);
unsigned line_find(int anArray[], int aSize, int aKey);
void printArray(int anArray[], int start, int end);
int errorCode = 0;

int searchIn(int anArray[], int leftBound, int rightBound, int key){
    errorCode = 0;
    int midpoint = leftBound + (rightBound-leftBound)/2;
    //printf("Midpoint: %d\n", midpoint);
    //getchar();
    if(anArray[midpoint] == key) return midpoint; //element found, end recursion
    if((leftBound + 1 == rightBound) && leftBound != key){
        errorCode = 1;
        return 0; //element not found
    }
    if(key > anArray[midpoint]){ //element is right of midpoint
        //printArray(anArray, midpoint, rightBound);
        searchIn(anArray, midpoint, rightBound, key);
    }else{ //or left of midpoint
        //printArray(anArray, leftBound, midpoint);
        searchIn(anArray, leftBound, midpoint, key);
    }
}

unsigned line_find(int anArray[], int aSize, int aKey)
{
	unsigned theResult = 0;
    errorCode = 1;
	for (unsigned i = 0; i < aSize; i++)
	{
		if (anArray[i] == aKey)
		{
		    errorCode = 0;
			theResult = i;
			break;
		}
	}

	return theResult;
}

int *generateOrdArray(int size){
    srand(time(NULL));
    int *anArray = (int *)malloc(sizeof(int)*size);
    int seed = 0;
    for(int i = 0; i<size; i++){
        seed += rand() %2;
        *(anArray + i) = seed;
    }
    return anArray;
}

void printArray(int anArray[], int start, int end){
	printf("{");
	for (int i = start; i < end; i++){
		printf(" %d ", anArray[i]);
	}
	printf("}\n");
}
