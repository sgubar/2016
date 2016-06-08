//
//  main.c
//  demoFind
//
//  Created by Slava Gubar on 5/10/16.
//  Copyright © 2016 Slava Gubar. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordArray.h"
#include "find.h"


int main(int argc, const char * argv[])
{
	ordArrayPtr theArray = oa_create(50000);
	int unordArray[50000];
	int count = 0;
	double time1 = 0, time2 = 0;

	clock_t  theStart, theEnd, theStart1, theEnd1;

	srand(0);
	for (int i = 0; i < 49990; i++)
	{
		oa_insert(theArray, rand() % 50000);
		unordArray[i] = rand() % 50000;
		count++;
	}

	oa_print(theArray);
	printf("\n\n");
	uoa_print(unordArray,count);

	printf("\nLooking for the index with value %d using binary algorithm...\n", theArray->storage[49980] );
	printf("Looking for the index with value %d using linear algorithm...\n\n", unordArray[49980]);

	theStart = clock();
	unsigned theIndex1 = oa_find(theArray, theArray->storage[49980]);
	theEnd = clock();
	printf("Time of searching using binary algorithm: %.10lf\n", time1=(double)(theEnd - theStart) / CLOCKS_PER_SEC);
	printf("The index found: %d\n\n", theIndex1);

	theStart1 = clock();
	unsigned theIndex2 = line_find(unordArray, count, unordArray[49980]);
	theEnd1 = clock();
	printf("Time of searching using linear algorithm: %.10lf\n", time2=(double)(theEnd1 - theStart1) / CLOCKS_PER_SEC);
	printf("The index found: %d\n\n", theIndex2);


	printf("**********CONCLUSION**********\n");
	printf("Binary algorithm is %.10lf seconds faster than linear algorithm\n", time2 - time1);
	
	return 0;

}
