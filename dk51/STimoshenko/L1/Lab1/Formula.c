//
//
// Laboratorna1
//
// Created by Sorokin Dmytro on 10/03/16.
// Copyright © 2016 Timoshenko Serj. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include "Formula.h"
#include "Function.h"

float Form();

float Form(float A, float B, float C)
{
	
		float Formula = ((A*A + B*B) / (B + doPWR(C))) + doFCTRL(B);//
		printf("3HA4EHH9 BUPA3Y=%.3f\n", Formula);
	
	
}
