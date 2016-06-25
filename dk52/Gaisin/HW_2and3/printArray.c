#include <stdio.h>

#include "printArray.h"

void printArray(int *arrayy, int Asize)
{
	printf("{");
	for(int i=0; i<Asize; i++)
		printf("%i, ", arrayy[i]);
	printf("}\n");
}
