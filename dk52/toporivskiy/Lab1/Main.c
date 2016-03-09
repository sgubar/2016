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
//#include "hex_oct.h"

int main()
{
	int number;
	printf("Enter decimal numer (no more than 1048576): \n");
	scanf("%d", &number);
	dec_bin(number);
	//hex_oct();

	return 0;
}
