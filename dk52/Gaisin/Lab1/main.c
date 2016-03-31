#include <stdio.h>
#include <math.h>/*mathematical library*/

#include "sum.h"/*this three library it header files when conected "main.c" with other ".c" files*/
#include "csqrt.h"
#include "fact.h"

int main ()
{
	int q, a, b,c; /*declarations variables*/
	printf("enter a\n");
	scanf("%i", &a);
	scanf("%i", &c);
	scanf("%i", &b);
//	int theFact = dofact(fac);/*appropriation variables theFact and other, value "fac" ...*/
//	int theCsqrt = docsqrt(sqrt(pt) / b);
//	int theSum = dosum(w,c);
	q = 0;
	if (b != 0)
	{
		q = a * docsqrt(b, c)/b + dosum(a, c);
	}
	
	printf("result %i\n", q);
	return 0;
}
