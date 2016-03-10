
#include "Header.h"

int fac(int n) {   //factorial of n
	int k = 1;  
	for (int i = 1; i <= n; i++) //while i is less or equal n, it increases by 1

		k *= i; //while "i" less then "n" this condition is done
	return k;
}

double f(int a, int b, int c) {
	double q = 0;
	q += (double)(a*b) / (b + c*c);
	for (int i = 0; i <= b; i++) q += fac(i); // on each iteration of  cycle to "q" add value that returns fac function
	return q;
}