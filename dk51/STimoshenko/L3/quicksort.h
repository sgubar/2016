
#ifndef quicksort_h
#define quicksort_h

#include <stdio.h>

int partitionIt(int anArray[], int aLeftIndex, int aRightIndex, int aPivot);
void quickSort(int anArray[], int aLeftIndex, int aRightIndex);
void quickSort2(int anArray[], int aLeftIndex, int aRightIndex);

#endif