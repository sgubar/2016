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
#include "powC.h"
#include "sum.h"
#include "division.h"
int main()
{
	int Q=0; /*a temporary variable initialization*/
	Q=division()+FactorialB(); /*calculating functions "division" and "FactorialB". The last operation at the task*/
	printf("Q=%i", Q); /*display the result of the task*/
	return 0;
}

