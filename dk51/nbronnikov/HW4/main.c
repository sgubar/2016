//
//  main.c
//  demoFind
//
//  Created by Bronnikov Nazar on 08/06/16.
//  Copyright © 2016 Bronnikov Nazar. All rights reserved.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#include "ordArray.h"
#include "find.h"

#define ARR_SIZE1 (100000)

int main()
{
	ordArrayPtr theArray;
	theArray = oa_create(ARR_SIZE1);
	int theArray1[ARR_SIZE1];
	
	clock_t start1, end1, start2, end2;
	
	srand(time(NULL));
	
	for (int i = 0; i < ARR_SIZE1; i++)
	{
		oa_insert(theArray, rand());
		theArray1[i] = rand();
	}
	
	clock_t time, time1;
	
	time = clock();
	unsigned theIndex1 = oa_find(theArray, 3);
	time = clock() - time;
	printf("Time of binary search of %d elements = [%.10f]\n", ARR_SIZE1, (double)(time) / CLOCKS_PER_SEC);
	
	time1 = clock();
	unsigned theIndexLine1 = line_find(theArray1, ARR_SIZE1, 8);
	time = clock() - time;
	printf("Time of line search of %d elements = [%.10f]", ARR_SIZE1, (double)(time1) / CLOCKS_PER_SEC);
	
	oa_destroy(theArray);
	
	system("pause");
}
