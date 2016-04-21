//
//  main.c
//  Lab1
//
//
//  Created by Iryna Bevza.
//  Copyright (C) 2016 Iryna Bevza. All rights reserved.
//
#include <stdio.h>
#include "powC.h"
int PowC() /*initialization of function "PowC"*/
{
	int C=0, y=0, powC; /*a temporary variable initialization*/
	printf("Enter C\n"); /*print at screen "Enter C"*/
	scanf("%i", &C);/*readout value of variable "C"*/
	powC=1;
	y=0;
	do {
	powC=powC*5;
	y++;
}
	while (y!=C);
	printf("PowC=%i\n", powC);/*print at screen value of "PowC"*/
	return PowC; /*calculating the value of "PowC" by doing cycle: multiply value of "FactorialB" and 5 C times*/
}
