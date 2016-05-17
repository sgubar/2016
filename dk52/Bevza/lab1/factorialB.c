//
//  main.c
//  Lab1
//
//
//  Created by Iryna Bevza.
//  Copyright (C) 2016 Iryna Bevza. All rights reserved.
//
#include <stdio.h>
#include "factorialB.h"
int B; /*a global variable initialization*/
int FactorialB() /*initialization of function "FactorialB"*/
{
	int x=0, factorialB; /*a temporary variable initialization*/
	printf("Enter B\n"); /*print at screen "Enter B"*/
	scanf("%i", &B); /*readout value of variable "B"*/
	factorialB=1;
	x=1;
	do {
	factorialB=factorialB*(B--);
}
/*calculating the value of "B!" by doing cycle: multiply value of "FactorialB" B times*/
	while (B!=1);
	printf("FactorialB=%i\n", factorialB);
	return FactorialB;
}
