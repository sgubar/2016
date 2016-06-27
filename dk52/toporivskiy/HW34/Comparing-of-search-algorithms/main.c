//
//  main.c
//  demoFind
//
//  Created by Andrew Toporivskyi on 02/06/2016.
//  Copyright © 2016 Andrew Toporivskyi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordArray.h"
#include "find.h"

int main(int argc, const char * argv[])
{
	// Create array
	ordArrayPtr anArray = oa_create(10000);

	// Fill array by random numbers
	srand(0);
	for (int i = 0; i < 10000; i++)
	{
		oa_insert(anArray, rand() % 10000); // (From 0 to 10000)
	}

	// Aaaand we start this code that will calculating runnig time of function
	printf("Test Line searching\n");
	clock_t theStartLine = clock();
	line_find(anArray->storage, anArray->size, anArray->storage[500]);
	clock_t theEndLine = clock();
	printf("time of Line searching: %.10lf\n", (double)(theEndLine - theStartLine) / CLOCKS_PER_SEC);

	printf("\nTest Bin searching\n");
	clock_t theStartBin = clock();
	oa_find(anArray, anArray->storage[500]);
	clock_t theEndBin = clock();
	printf("time of Bin searching: %.10lf\n", (double)(theEndBin - theStartBin) / CLOCKS_PER_SEC);

	//oa_print(anArray); // For testings
	system("pause");
}
