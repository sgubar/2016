// formula.c
//
// Created by Stanislav Bashkirov on 8/03/2016
// Copyright (C) 2016 Stanislav Bashkirov. All rights reserved.

#include <stdio.h>
#include "formula.h"
#include "SimpleMath.h"

void calculate(int A, int B, int C);

void calculate(int A, int B, int C)
{ 
	if ((B + Pow2(C,2)) != 0)
	{
		double Result = ((A*B) / (B + Pow2(C, 2))) + Summ(B);
		printf("Final result: %f\n", Result);
	}
	else 
		printf("Invalid arguments!\n");
}