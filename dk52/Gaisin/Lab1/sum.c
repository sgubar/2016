#include <stdio.h>
#include <stdlib.h>

#include "sum.h"

int dosum()
{
	int p, e, sum = 1;
	printf("enter again c\n");
	scanf("%i", &e);
	for (p = 0; p < (e + 1); p++)
	{
		sum += p;
	}
	printf("sum = %i\n", sum);
	return sum;
}
