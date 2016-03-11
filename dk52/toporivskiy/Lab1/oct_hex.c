//
//  oct_hex.c
//  Lab1
//
//  Created by Andrew Toporivskiy on 11/03/16 (DD/MM/YY).
//  Copyright (C) 2016 Andrew Toporivskiy. All rights reserved.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> 

#include "oct_hex.h"

void oct_hex()
{
	// Initialization
	int oct_hex_Number;

	// Translation from hexadecimal to octal and output on the screen
	printf("Enter hexadecimal number:\n");
	scanf("%o", &oct_hex_Number);
	printf("Octal equivalent of number is %x\n", oct_hex_Number);

	// Keeping the console open
	system("pause");
	printf("\n");
	printf("\n");
	main();
}
