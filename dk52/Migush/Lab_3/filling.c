#include <stdio.h>
#include <stdlib.h>

void gener_array(int *a,int *b,int *c,int *d,int *e) /*fanction that craete numbers*/
{
	int i;
	for(i=0; i<1000; i++)
	{
		a[i] = rand()%10; /*assigned cell array random number (0<= number <10)*/
		b[i] = a[i];
		c[i] = a[i];
		d[i] = a[i];
		e[i] = a[i];
	}
	printf("\n");
}

void printArray(int anArray[], int aSize)
{
	int i;
	printf("{");
	for (i = 0; i < aSize; i++)
	{
		printf(" %d ", anArray[i]);
	}

	printf("}\n");
}

