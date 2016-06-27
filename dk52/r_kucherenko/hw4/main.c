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


int main(int argc, const char * argv[])
{
    int aSize;
        printf ("Enter the length of mass:");
        scanf("%d", &aSize);
	ordArrayPtr theArray = oa_create(aSize);
	
	srand(0);
	for (int i = 0; i < aSize; i++)
	{
		oa_insert(theArray, rand() % 180);
	}
        unsigned randIndex=rand() % aSize;
        printf("Random index: %d;\nIts value: %d",randIndex,theArray->storage[randIndex]);
        
	oa_print(theArray);
        printf("\nTest binaryfind\n");
       	clock_t Start=clock();
	unsigned theIndex = RecursiveBinarySearch(theArray->storage,0,aSize-1,theArray->storage[randIndex]);
	clock_t End=clock();
	printf("\ntheIndex: %d,\nTime= %.12lf\n",theIndex,(double)(End- Start)/CLOCKS_PER_SEC);
	
        
        printf("\nTest linefind\n");
        Start=clock();
	theIndex = RecursiveBinarySearch(theArray->storage,0,aSize-1,theArray->storage[randIndex]);
        End=clock();
	printf("\ntheIndex: %d,\nTime= %.12lf\n",theIndex,(double)(End- Start)/CLOCKS_PER_SEC);
        
}

