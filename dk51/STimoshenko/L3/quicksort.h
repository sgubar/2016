//
//  quicksort.h
//  
//
//  Created by Serj Timoshenko on 4/18/16.
//  Copyright © 2016 Serj Timoshenko. All rights reserved.
//
#ifndef quicksort_h
#define quicksort_h

#include <stdio.h>

int partitionIt(int anArray[], int aLeftIndex, int aRightIndex, int aPivot);
void quickSort(int anArray[], int aLeftIndex, int aRightIndex);
void quickSort2(int anArray[], int aLeftIndex, int aRightIndex);

#endif