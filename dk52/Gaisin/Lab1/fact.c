#include <stdio.h>

#include "fact.h"

int dofact(int aParam)
{
#if 0
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
#else
	
	int theResult = 1;
	
	if (aParam > 0)
	{
		for (int i = 1; i <= aParam; i ++)
		{
			theResult *= i;
		}
	}
	
	return theResult;
	
#endif
}

int doFact2(int aParam)
{
	if (aParam == 1 || aParam == 0) return 1;
	
	return aParam * doFact2(aParam - 1);
}
