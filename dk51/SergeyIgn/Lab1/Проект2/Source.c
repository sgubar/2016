#include <stdio.h> 
#include <math.h> 
int fact(int c)
{
	if (c < 0) // если пользователь ввел отрицательное число 
		return 0; // возвращаем ноль 
	if (c == 0) // если пользователь ввел ноль, 
		return 1; // возвращаем факториал от нуля 
	else // Во всех остальных случаях 
		return c * fact(c - 1); // делаем рекурсию. 
}
double q(int);
int main()
{
	int a, b, c, d = 0;
	int sum = 0, k;
	printf ("Enter a for query q = sqrt(b+c)/b + sumC D=0 (A+D)!\n");
	scanf ("%d", &a);
	printf("Enter b for query q = sqrt(b+c)/b + sumC D=0 (A+D)!\n");
	scanf ("%d", &b);
	printf ("Enter c for query q = sqrt(b+c)/b + sumC D=0 (A+D)!\n");
	scanf ("%d", &c);
	double q = (a * sqrt(b + c) / b + fact(a)*(c + 1));
	printf ("%d\n", q);
	system ("pause");
}