#include <stdio.h>
#include <stdlib.h>
#include "Function.h"

float doFCTRL(float B);
float doPWR(float C);


float doFCTRL(float B)
{
	int i;
	int k = 1;
	for (i = B; i != 1; i--)
	{
		k = k*i;
	}
	return (k);
}

float doPWR(float C)
{
	int j;
	int m = 1;
	for (j = 0; j != C; j++)
		m = m * 5;
	return (m);
}