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

int main()
{
// Entry point
	printf("OPERATION:\n");
	printf("1) Translate from decimal to binary\n");
	printf("2) Translate from hexadecimal to octal\n");
	printf("\n");
	int operation, dec_bin_Number;
	char hex_oct_Number[20];
// Choose operation and checkup
	do {
		printf("Enter number of operation:\n");
		scanf("%d", &operation);
		printf("\n");
	} while (operation != 1 && operation != 2);
// Output operation on screen
	if (operation == 1) {
		printf("Enter decimal number (no more than 1048576):\n");
		scanf("%d", &dec_bin_Number);
		dec_bin(dec_bin_Number);
	} else if (operation == 2) {
		int str = strlen(hex_oct_Number);
		printf("Enter hexadecimal number (no more than 16^20):\n");
		scanf(" %c", &hex_oct_Number);
		printf("%c", hex_oct_Number[1]);
		printf("%c", hex_oct_Number[2]);
		//hex_oct(hex_oct_Number);
	} else {
		printf("FATAL ERROR!!!\n"); // Be on the safe side ;)
	}
	system("pause");
	return 0;
}
