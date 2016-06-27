/*																 /
/  compare.h       	                                             /
/  compare sort                                                  /
/                                                                /
/  Created by Sergey Ninoshvili on 25/6/16.                      /
/  Copyright © 2016 Sergey Ninoshvili. All rights reserved.      /
/																*/
#ifndef COMPARE_H
#define COMPARE_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *createArray(int size, int pivot);

void PArray(int *Array, int size);

void bubbleRezult();

void selectionRezult();

void insertionRezult();

void shellRezult();

void quickRezult();

#endif
