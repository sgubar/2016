#include <math.h>
long int factorial(long int n)
{
	if (n == 0 || n == 1) return 1;
	return n * factorial(n - 1);
}

long int sumToC(int c, int a)
{
	long int sum = 0;
	for (int d = 0; d <= c; d++)
	{
		sum += factorial(a + d);
	}
	return sum;
}
float firstPartExpression(int a, float b, int c)
{
	float q;
	return q = a * (sqrt(b + c) / b);
}
