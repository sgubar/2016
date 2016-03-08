#include<stdio.h>

#include"Math.h"
#include"InputHEX.h"

int doInputHEX();
int Sub(int numberB);
int Sum(int resultSub, int numberD);

int Sub(int numberB) {
	int resultSub = doInputHEX() - numberB;
	printf("Sub=%d\n", resultSub);
	return(resultSub);
}



int Sum(int resultSub, int numberD)
{
	int resultMult, result = 0;
	for (int A=1 ; A <= numberD; A++)
	{
		resultMult = resultSub*A;
		result += resultMult;
	}
	printf("RESULT=%d\n", result);
	return(result);
}