//
//  bin_dec.c
//  Lab1
//
//  Created by Andrew Toporivskiy on 11/03/16 (DD/MM/YY).
//  Copyright (C) 2016 Andrew Toporivskiy. All rights reserved.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "bin_dec.h"

void bin_dec(long bin_dec_Number)
{
	// Initialization
	long decimal = 0, base = 1, remainder;

	// Translation from decimal to binary
	for (base; bin_dec_Number > 0; base*=2)
	{
		remainder = bin_dec_Number % 10;
		decimal = decimal+ remainder * base;
		bin_dec_Number /= 10;
	}
	
	// Output on the screen
	printf("Decimal equivalent of number is:\n");
	printf("%d\n", decimal);

	// Keeping the console open
	system("pause");
	printf("\n");
	printf("\n");
	main();
}


// Variant #2
/*
int dec_bin(long dec_bin_Number)
{
// Initialization
long remainder, base=1, binary=0;

// Translation from decimal to binary
for (base; dec_bin_Number > 0; base *= 10) {
remainder = dec_bin_Number % 2;
binary += remainder*base;
dec_bin_Number /= 2;
}

// Return value
return binary;
}
*/