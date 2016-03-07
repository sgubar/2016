//
//  MulComplexity.c
//  demo16
//
//  Created by Slava Gubar on 2/14/16.
//  Copyright © 2016 Slava Gubar. All rights reserved.
//

#include <stdio.h>
#include "MulComplexity.h"

static void doSlowly(int aParamA, int aParamB, int aParamC);
static void doFastest(int aParamA, int aParamB);

void doMulComplexity()
{
	printf ("The complexity of multiplication");
	
	doSlowly(10, 10, 10); //<! - O(n^3)
	doFastest(10, 10);
	
	printf("O (f(n) * g(n)) = O(n^3) + O(n^3) * O(n^2) = O (n^5)\n");
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
			doSlowly(3, 3, 3);
		}
	}
	
	printf("[doFastest]. The sum = %ld\n", theSum);
}

