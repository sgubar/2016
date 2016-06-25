#include <stdio.h>
#include <malloc.h> //library for dynamic allocation memory
#include <stdlib.h> //library for generate random namber

#include "printArray.h"
#include "sortArray.h"

int main() 
{
	int *arrayy;  //pointer on array
	int Asize;
	printf("Enter size array: ");
	scanf("%i", &Asize);
	arrayy = (int*) malloc(Asize*sizeof(int)); //dynamic allocation memory
	for(int i=0; i<Asize; i++) //cycle "for"
		arrayy[i] = rand() %10; //filling array ranodm nambers 0<=x<=9
	printArray(arrayy, Asize); //function output on screen 

	sortArray(arrayy, Asize);
	printf("\nsorted array \n");
	printArray(arrayy, Asize);
	free(arrayy); //function release memory
	return 0;
}
