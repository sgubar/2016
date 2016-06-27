//
//  main.c
//  demoFind
//
//  Created by Slava Gubar on 5/10/16.
//  Copyright © 2016 Slava Gubar. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "ordArray.h"

int main(int argc, const char * argv[])
{
	ordArrayPtr theArray = oa_create(1000); /*create array for 1000 elements with random values*/
	
	srand(0);
	for (int i = 0; i < 1000; i++) /*random values */
	{
		oa_insert(theArray, rand() % 1000);
	}

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

	system("pause");
}
