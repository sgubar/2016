//
//  fillArray.c
//  Lab3_Sort
//
//  Created by Andrew Toporivskiy on 09/05/16 (DD/MM/YY).
//  Copyright (C) 2016 Andrew Toporivskiy. All rights reserved.
//

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))

#include <stdio.h>
#include <stdlib.h>

void fillArray(int anArray[], int aSize) {
	srand(0);
	for (int i = 0; i < aSize; i++)
	{
		anArray[i] = rand();
	}
}