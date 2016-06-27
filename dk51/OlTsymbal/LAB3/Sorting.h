
#ifndef Sorting_h
#define Sorting_h

#include <stdio.h>

void bubbleSort(int anArray[], int aSize);
void selectionSort(int anArray[], int aSize);
void insertionSort(int anArray[], int aSize);
void shellSort(int anArray[], int aCount);

int partitionIt(int anArray[], int aLeftIndex, int aRightIndex, int aPivot);
void quickSort(int anArray[], int aLeftIndex, int aRightIndex);
void quickSort_v2(int anArray[], int aLeftIndex, int aRightIndex);

#endif /*Sorting_h */
