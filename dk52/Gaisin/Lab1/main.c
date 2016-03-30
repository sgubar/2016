#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "sum.h"
#include "csqrt.h"
#include "fact.h"

int main ()
{
	int q, w, fac, pt, b, sum;
	printf("enter a\n");
	scanf("%i", &w);
	int theFact = dofact(fac);
	int theCsqrt = docsqrt(sqrt(pt) / b);
	int theSum = dosum(sum);
	q = w * theCsqrt + theSum * theFact;
	printf("result %i\n", q);
	return 0;
}
