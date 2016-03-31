#include <stdio.h>

#include "sum.h"/*conect by using header file*/
#include "fact.h"

int dosum(int A, int C)
{
#if 0
	int p, e, sum = 1;
	printf("enter again c\n");
	scanf("%i", &e);
	if(e > 0)
	{
	for (p = 0; p < (e + 1); p++)/*cycle counting between 1 to (a+1) and adds sum until p < (e+1)*/
	{
		sum += p;
	}
	printf("sum = %i\n", sum);
	return sum;/*return result "sum"*/
	}
	else
	{
		printf("error\n");
	}
#else
	int theSum = 0;
	for (int D = 0; D < C; D ++)
	{
		theSum += dofact(A + D);
	}
	
	return theSum;
#endif
}
