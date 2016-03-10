#include <stdio.h>
#include "formula.h"
#include "SimpleMath.h"

void calculate(int A, int B, int C);

void calculate(int A, int B, int C)
{ 
	if ((B + Pow2(C,2)) != 0)
	{
		printf("A*B = %d \n",(A*B));
		printf("B + Pow2(C, 2) = %f\n", (B + Pow2(C, 2)));
		printf("Summ(B) = %f\n", Summ(B));
		double Result = ((A*B) / (B + Pow2(C, 2))) + Summ(B);
		printf("Final result: %f\n", Result);
	}
	else 
		printf("Invalid arguments!\n");
}