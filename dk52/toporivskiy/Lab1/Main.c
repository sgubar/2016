//
//  Main.c
//  Lab1
//
//  Created by Andrew Toporivskiy on 29/02/16 (DD/MM/YY).
//  Copyright (C) 2016 Andrew Toporivskiy. All rights reserved.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "dec_bin.h"
#include "hex_oct.h"
#include "oct_hex.h"

int main()
{
// Entry point
	printf("CHOOSE OPERATION:\n");
	printf("1) Translate from decimal to binary\n");
	printf("2) Translate from binary to decimal\n");
	printf("3) Translate from hexadecimal to octal\n");
	printf("4) Translate from octal to hexadecimal\n");
	printf("5) Exit\n");
	printf("\n");
	int operation;
	long dec_bin_Number, bin_dec_Number;
// Choose operation and checkup
		do {
			printf("Enter number of operation:\n");
			scanf("%d", &operation);
			printf("\n");
		} while (operation != 1 && operation != 2 && operation != 3 && operation != 4 && operation != 5);
// Output operation on the screen
	if (operation == 1) {
		do {
			printf("Enter positive decimal number:\n");
			scanf("%ld", &dec_bin_Number);
		} while (dec_bin_Number < 0);
		dec_bin(dec_bin_Number);
	} else if (operation == 2) {
		printf("Enter binary number:\n");
		scanf("%ld", &bin_dec_Number);
		bin_dec(bin_dec_Number);
	} else if (operation == 3) {
		hex_oct();
	} else if (operation == 4) {
		oct_hex();
	} else if (operation == 5) {
		return 0;
	} else {
		printf("FATAL ERROR!!!\n"); // Be on the safe side ;)
	}
	return 0;
}