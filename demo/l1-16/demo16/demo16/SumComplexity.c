//
//  SumComplexity.c
//  demo16
//
//  Created by Slava Gubar on 2/14/16.
//  Copyright © 2016 Slava Gubar. All rights reserved.
//

#include <stdio.h>
#include "SumComplexity.h"

static void doSlowly(int aParamA, int aParamB, int aParamC);
static void doFastest(int aParamA, int aParamB);

void doSumComplexity()
{
	printf ("The complexity of summary");
	
	doSlowly(10, 3, 10);//<! n^3
	doFastest(10, 10); //<! n^2
	
	printf("O (max (f(n), g(n)) = O(n^3)\n");
	printf("Thanks!\n");
}

// O (n^3)
void doSlowly(int aParamA, int aParamB, int aParamC)
{
	long theSum = 0;
	
	for (int i = 0; i < aParamA; i ++)
	{
		for (int j = 0; j < aParamB; j ++)
		{
			for (int k = 0; k < aParamC; k ++)
			{
				theSum += 1;
			}
		}
	}
	
	printf("[doSlowly]. The sum = %ld\n", theSum);
}

// O (n^2)
void doFastest(int aParamA, int aParamB)
{
	long theSum = 0;
	
	for (int i = 0; i < aParamA; i ++)
	{
		for (int j = 0; j < aParamB; j ++)
		{
			theSum += 1;
		}
	}
	
	printf("[doFastest]. The sum = %ld\n", theSum);
}

