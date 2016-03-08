#include<stdio.h>

#include"Math.h"
extern int number, A, C, B, D;

extern int Sub();
extern int Mult();
int Sum();

int Sub(int Sub) {
	Sub = number - C;
	printf("Sub=%d\n", Sub);
	return(Sub);
}

int Mult(int Mult)
{
    Mult =(int) Sub*A;
	printf("Mult=%d\n", Mult);
	return(Mult);
}

int Sum()
{
	int A = 1;
	int result,i = 0;
	for (i =A ; i <= D; i++)
	{
		result = Mult;
		result +=(int) Mult;
	}
	printf("Sum=%d\n", result);
	return(result);
}