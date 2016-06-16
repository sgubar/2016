#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ordArray.h"
#include "find.h"

void main(int argc, const char * argv[])
{
	ordArrayPtr theArray = oa_create(2000);
	
	srand(0);
	for (int i = 0; i < 2000; i++)
	{
		oa_insert(theArray, rand() % 180);
	}

	oa_print(theArray);
	
	clock_t theStart = clock();
	unsigned theIndex = oa_find(theArray, theArray->storage[1000]);
	clock_t theEnd = clock();
	
	printf ("\ntime of binary find: %.10lf\n", (double)(theEnd - theStart)/CLOCKS_PER_SEC);
	printf("\ntheIndex: %d\n\n", theIndex);
	

	int aSize = 2000;
	int ttheArray [2000];
	printf("{");
	for(int i = 0; i < 2000; i++)
	{
		ttheArray[i] = rand()%180;
		printf("%i,", ttheArray[i]);
	}
	printf("}");
	clock_t theStart1 = clock();
	unsigned theIndex2 = line_find(ttheArray, aSize, ttheArray[1000]);
	clock_t theEnd1 = clock();

	printf ("\ntime of line find: %.10lf\n", (double)(theEnd1 - theStart1)/CLOCKS_PER_SEC);
	printf("the result  = %i\n", theIndex2);
}
