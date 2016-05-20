//
//  Lab3
// 
//
//  Created by Nazar Bronnikov on 15/05/16.
//  Copyright (C) 2016 Nazar Bronnikov. All rights reserved.
//

#ifndef quickSort_h
#define quickSort_h

#include <stdio.h>

int partitionIt(int anArray[], int aLeftIndex, int aRightIndex, int aPivot);
void quickSort(int anArray[], int aLeftIndex, int aRightIndex);
void quickSort2(int anArray[], int aLeftIndex, int aRightIndex);

#endif /* quickSort_h */
