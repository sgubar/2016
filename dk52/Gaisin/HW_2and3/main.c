#include <stdio.h>
#include <malloc.h> //library for dynamic allocation memory
#include <stdlib.h> //library for generate random namber

#include "printArray.h"

int main() 
{
	int *arrayy;  //pointer on array
	int Asize;
	printf("Enter size array: ");
	scanf("%i", &Asize);
	if(Asize > 0)
	{
		arrayy = (int*) malloc(Asize*sizeof(int)); //dynamic allocation memory
	}
	else
	{
		printf("Error\n");
		return 0;
	}
	for(int i=0; i<Asize; i++) //cycle "for"
		arrayy[i] = rand() %10; //filling array ranodm nambers 0<=x<=9
	printArray(arrayy, Asize); //function output on screen 
	free(arrayy); //function release memory
	return 0;
}
