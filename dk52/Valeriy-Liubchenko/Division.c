#include "factorial.h"
#include "Module.h"

void Division ()
	{
		float c;
int fac_output, module_output,fac_input,A,B;
	
	printf ("Enter A , please\n");
	scanf ("%d",&A);
	printf ("Enter B, please\n");
	scanf ("%d",&B);
	fac_input=A;
	c = factorial(fac_input)/Module(A,B);
		printf("%0.2f",c);
}