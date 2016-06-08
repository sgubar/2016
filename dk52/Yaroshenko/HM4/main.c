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
{	 int i=0;
	ordArrayPtr theArray = oa_create(100000);
	int UnsortedArray[100000];
	srand(0);
	for ( i; i < 100000; i++)
	{
		oa_insert(theArray, rand() % 100000);
		UnsortedArray[i]=rand() % 100000;
	}

	//oa_print(theArray);
	

	 //UnsortPrint(UnsortedArray,i);
	 
	 //Meryaem vremya binarnogo poiska
	clock_t Start1= clock();
	unsigned theIndex = oa_find(theArray, theArray->storage[74039]);
	clock_t End1 = clock(),time1;
	printf("Using the binary search we spent %.10lf seconds",time1=(long double)(End1 - Start1) / CLOCKS_PER_SEC);
	printf("\ntFound : %d\n", theIndex);
	
	
	//meryaem vremya lineinogo poiska	
	clock_t Start2=clock();
	unsigned theIndex1=line_find(UnsortedArray,i+1,UnsortedArray[74039]);
	clock_t End2=clock(),time2;
	printf("Using the linear search we spent %.10lf seconds\n",time2=(long double)(End2 - Start2) / CLOCKS_PER_SEC);
	printf("\nFound index: %d\n", theIndex1);	
	
	//sravnivaem zatrachennoe vremya 
	printf("So binary search is %.10lf times faster than linear one",(long double)time2/time1);
	
}
