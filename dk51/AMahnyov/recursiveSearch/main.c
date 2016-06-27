/*Copyright (c), 2016, Mahnyov Aleksander. All rights reserved*/
#include <stdio.h>
#include <stdlib.h>

static int *generateOrdArray(int size);
static void printArray(int anArray[], int start, int end);
int searchIn(int anArray[], int leftBound, int rightBound, int key);
int errorCode = 0;

int main(){
    int *searchArray = generateOrdArray(15);
    printf("Generated array: \n");
    printArray(searchArray, 0, 15);
    printf("Enter the element to search for: ");
    int key;
    scanf("%d", &key);
    printf("Found at: %d\n", searchIn(searchArray, 0, 15, key));
    printf("Error code: %d\n", errorCode);
    return 0;
}

int searchIn(int anArray[], int leftBound, int rightBound, int key){
    errorCode = 0;
    int midpoint = leftBound + (rightBound-leftBound)/2;
    printf("Midpoint: %d\n", midpoint);
    getchar();
    if(anArray[midpoint] == key) return midpoint; //element found, end recursion
    if((leftBound + 1 == rightBound) && leftBound != key){
        errorCode = 1;
        return 0; //element not found
    }
    if(key > anArray[midpoint]){ //element is right of midpoint
        printArray(anArray, midpoint, rightBound);
        searchIn(anArray, midpoint, rightBound, key);
    }else{ //or left of midpoint
        printArray(anArray, leftBound, midpoint);
        searchIn(anArray, leftBound, midpoint, key);
    }
}

static int *generateOrdArray(int size){
    srand(time(NULL));
    int *anArray = (int *)malloc(sizeof(int)*size);
    int seed = 0;
    for(int i = 0; i<size; i++){
        seed += rand() %10;
        *(anArray + i) = seed;
    }
    return anArray;
}

static void printArray(int anArray[], int start, int end){
	printf("{");
	for (int i = start; i < end; i++){
		printf(" %d ", anArray[i]);
	}
	printf("}\n");
}

/* Here is the search function without demo stuff:
int searchIn(int anArray[], int leftBound, int rightBound, int key){
    int midpoint = leftBound + (rightBound-leftBound)/2;
    if(anArray[midpoint] == key) return midpoint;
    if(key > anArray[midpoint]){
        searchIn(anArray, midpoint, rightBound, key);
    }else{
        searchIn(anArray, leftBound, midpoint, key);
    }
}*/
//TODO: fix "element not found issue"2
