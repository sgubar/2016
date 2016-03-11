#include "sum.h"
#include "fract.h"
#include <stdio.h>

void Algorithm ()
	{
int A,B,C,rez;
float result;
start:	
	printf ("Enter A\n");
	scanf ("%d",&A);
	printf ("Enter B\n");
	scanf ("%d",&B);
	if (B == 0) 
	{
	printf ("Please change the value B\n");
	goto start;
	}
	printf ("Enter C\n");
	scanf ("%d",&C);
	result=A*dofract(B,C)+dosum(A,C);
	printf("%f",result);
}
