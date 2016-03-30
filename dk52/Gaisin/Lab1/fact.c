#include <stdio.h>

#include "fact.h"

int dofact()
{
	int i, fac = 1, a;
	printf("enter again a\n");
	scanf("%i", &a);
	if(a > 0)
	{
	for (i = 1; i < (a + 1); i++) /*cycle counting between 1 to (a+1) and multiplies i*/
	{
		fac *= i;
	}
	printf("fac = %i\n", fac);
	return fac;
	}
	else
	{
		printf("error\n");
	}
}
