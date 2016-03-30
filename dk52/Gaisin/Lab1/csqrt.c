//create program when will calculate sqrt 
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "csqrt.h"

int docsqrt()
{ 
	int b, c, pt;
	printf("calculate csqrt\n");
	printf("enter b, c\n");
	scanf("%i" "%i", &b, &c);
	pt = b + c;
	if((b == 0) || (pt < 0))
	{
		printf("error, sorry...\nplease try again\n");
		return 0;
	}	
	else 
	{
		printf("csqrt = %f \n", sqrt(pt) / b);
		return sqrt(pt) / b;
	}
}
