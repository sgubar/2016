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
int B;
int FactorialB()
{
	int x=0;
	printf("Enter B\n");
	scanf("%i", &B);
	factorialB=1;
	x=1;
	do {
	factorialB=factorialB*(B--);
}
	while (B!=1);
	printf("FactorialB=%i\n", factorialB);
	return FactorialB;
}
