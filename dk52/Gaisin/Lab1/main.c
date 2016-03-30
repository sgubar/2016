#include <stdio.h>
#include <math.h>/*mathematical library*/

#include "sum.h"/*this three library it header files when conected "main.c" with other ".c" files*/
#include "csqrt.h"
#include "fact.h"

int main ()
{
	int q, w, fac, pt, b, sum; /*declarations variables*/
	printf("enter a\n");
	scanf("%i", &w);
	int theFact = dofact(fac);/*appropriation variables theFact and other, value "fac" ...*/
	int theCsqrt = docsqrt(sqrt(pt) / b);
	int theSum = dosum(sum);
	q = w * theCsqrt + theSum * theFact;
	printf("result %i\n", q);
	return 0;
}
