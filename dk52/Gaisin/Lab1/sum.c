#include <stdio.h>
#include <stdlib.h>

#include "sum.h"/*conect by using header file*/

int dosum()
{
	int p, e, sum = 1;
	printf("enter again c\n");
	scanf("%i", &e);
	for (p = 0; p < (e + 1); p++)/*cycle counting between 1 to (a+1) and adds sum until p < (e+1)*/
	{
		sum += p;
	}
	printf("sum = %i\n", sum);
	return sum;/*return result "sum"*/
}
