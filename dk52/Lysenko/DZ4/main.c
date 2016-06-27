#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordArray.h"
#include "find.h"

int main(int argc, const char * argv[])
{
	int i = 0;
	ordArrayPtr theArray = oa_create(10000);
	int UnsortedArray[10000];
	srand(0);
	for (i; i < 10000; i++)
	{
		oa_insert(theArray, rand() % 10000);
		UnsortedArray[i] = (rand() % 10000);
		
	}

	//oa_print(theArray);

	//UnsortPrint(UnsortedArray,i);
	

	//printf("\ntheIndex: %d\n", theIndex);
	//unsigned theIndex = oa_find(theArray, theArray->storage[10]);

	

	//Meryaem vremya binarnogo poiska
	clock_t Start1 = clock();
	unsigned theIndex = oa_find(theArray, theArray->storage[3228]);
	clock_t End1 = clock(), time1;
	printf("Using the binary search we spent %.10lf seconds", time1 = (long double)(End1 - Start1) / CLOCKS_PER_SEC);
	printf("\nFound : %d\n\n", theIndex);


	//meryaem vremya lineinogo poiska	
	clock_t Start2 = clock();
	unsigned theIndex1 = line_find(UnsortedArray, i + 1, UnsortedArray[3228]);
	clock_t End2 = clock(), time2;
	printf("Using the linear search we spent %.10lf seconds\n", time2 = (long double)(End2 - Start2) / CLOCKS_PER_SEC);
	printf("Found index: %d\n", theIndex1);

	//sravnivaem zatrachennoe vremya 
	//printf("Binary search is %.10lf times faster than linear one\n", (long double)time2 / (long double)time1);

	system("pause");
}
