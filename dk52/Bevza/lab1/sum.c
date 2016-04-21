//
//  main.c
//  Lab1
//
//
//  Created by Iryna Bevza.
//  Copyright (C) 2016 Iryna Bevza. All rights reserved.
//
#include <stdio.h>
#include "sum.h"
#include "powC.h"

int SUM1 () /*initialization of function "SUM1"*/
{
	int A=0, B; /*a temporary variable initialization*/
	printf("Enter A\n"); /*print at screen "Enter A"*/
	scanf("%i", &A); /*readout value of variable "A"*/
	sum1=A*A+B*B; /*calculating the sum of A squared and B squared*/
	return SUM1;
}
int SUM2 () /*initialization of function "SUM2"*/
{
	sum2=B+PowC; /*calculating the sum of variable B and function "PowC"*/
	if (sum2==0){
		printf("Error. SUM2=0\n"); /*Checing the value of SUM2. Print at screen "Error. SUM2=0" if value of function "SUM2" is 0*/
	}
	return SUM2;
