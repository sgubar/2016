//
//  hex_oct.c
//  Lab1
//
//  Created by Andrew Toporivskiy on 09/03/16 (DD/MM/YY).
//  Copyright (C) 2016 Andrew Toporivskiy. All rights reserved.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> 

#include "hex_oct.h"

void hex_oct(char hex_oct_Number)
{
// Initialization
	//char hex[16] = "0123456789ABCDEF";
	int str, cell = 0;
	str = sizeof(hex_oct_Number);
	printf("%d\n", str);
	int resultOctal[20];
	
	//for (cell; cell <= str; cell++) {}

/*
// Output on display
	for (cell; cell >= 0; cell--)
	{
		printf("%d", invertBinary[cell]);
	}
	printf("\n");
	*/

// Keeping the console open
	system("pause");
}
