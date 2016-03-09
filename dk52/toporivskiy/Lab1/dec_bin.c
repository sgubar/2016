//
//  dec_bin.c
//  Lab1
//
//  Created by Andrew Toporivskiy on 09/03/16 (DD/MM/YY).
//  Copyright (C) 2016 Andrew Toporivskiy. All rights reserved.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "dec_bin.h"

void dec_bin(int dec_bin_Number)
{
// Initialization
	int cell = 0, invertBinary[20];

// Translation from decimal to binary
	for (cell; dec_bin_Number >= 1; cell++)
	{
		invertBinary[cell] = dec_bin_Number % 2; // Writing remainder of the division into the array 
		dec_bin_Number /= 2;
	}
// Add last remainder of the division if it is not equal to 0
	if (dec_bin_Number == 1) {
		invertBinary[cell] = dec_bin_Number;
	} else {
		cell--;
	}

// Output on screen in reverse sequence
	for (cell; cell >= 0; cell--)
	{
		printf("%d", invertBinary[cell]);
	}
	printf("\n");

// Keeping the console open
	system("pause");
}