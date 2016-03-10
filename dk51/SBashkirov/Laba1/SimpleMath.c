#include "SimpleMath.h"

double Summ(int num);
double factorial(int fact);
double Pow2(int number, int stepen);

double Summ(int num) {
	int i,res = 0;
	num ++; 
	for (i = 0; i < num; i++)
	{
		res += factorial(i);
		printf("%f +", factorial(i));
	}
	return(res);
}
double factorial(int fact) {
	if (fact == 0) return (1);
	else {
		int res = 1;
		fact++;
		for (int i = 1; i < fact;i++)
			res *= i;
		return (res);
	}
}

double Pow2(int number, int stepen) 
{
	if (stepen == 0)  return(1); 
	int i,res = number;
	for (i = 1; i < stepen; i++)
		res *= number;
	return(res);
}
