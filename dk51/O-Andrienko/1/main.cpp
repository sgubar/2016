#include <stdio.h>
#include <stdlib.h>
#include "InputFunctions.h"
#include "checkFunctions.h"
#include "math.h"

void main()
{
	int a, c;
	float  b, Q;
	inputParams(&a, &b, &c);
	while (checkparams(a, b, c) != true) inputParams(&a, &b, &c);
	Q = firstPartExpression(a, b, c) + sumToC(c, a);
	printf("\n\n\n RESULT Q=%f",Q);
	getchar();
}

