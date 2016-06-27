#include <stdio.h>
#include <stdlib.h> //standard library for memory allocation
#include <time.h> //standard library for time

#include "ordArray.h"
#include "find.h"

void main(int argc, const char * argv[])
{
	ordArrayPtr theArray = oa_create(2000);
	
	srand(0); //declaration generator random nambers
	for (int i = 0; i < 2000; i++) 
	{
		oa_insert(theArray, rand() % 180); //fill array random namber from 0 befor 179
	}

	oa_print(theArray); //function output array
	
	clock_t theStart = clock(); //start clock
	unsigned theIndex = oa_find(theArray, theArray->storage[1000]);
	clock_t theEnd = clock(); //end clock
	
	//end minus start, and output time on screen
	printf ("\ntime of binary find: %.10lf\n", (double)(theEnd - theStart)/CLOCKS_PER_SEC);
	printf("\ntheIndex: %d\n\n", theIndex); //output index hundredth element
	

	int aSize = 2000;
	int ttheArray [2000]; //create array on 2000 elements 
	printf("{");
	for(int i = 0; i < 2000; i++) //that counts up to 2000 cycle
	{
		ttheArray[i] = rand()%180; //fill array random namber from 0 befor 179
		printf("%i,", ttheArray[i]); //output array whith random namber
	}
	printf("}");
	clock_t theStart1 = clock();
	unsigned theIndex2 = line_find(ttheArray, aSize, ttheArray[1000]);
	clock_t theEnd1 = clock();

	printf ("\ntime of line find: %.10lf\n", (double)(theEnd1 - theStart1)/CLOCKS_PER_SEC);
	printf("the result  = %i\n", theIndex2);
}
