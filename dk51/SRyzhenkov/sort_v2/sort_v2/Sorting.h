//  Sorting.h
//  sort_v2
//
//  Created by Ryzhenkov Serhii on 21/04/16.
//  Copyright � 2016 Ryzhenkov Serhii. All rights reserved.

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