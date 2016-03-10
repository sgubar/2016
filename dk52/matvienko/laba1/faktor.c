#include <stdio.h>
#include <conio.h>


int faktor(int A)
{
	int Af = 1;

	if (A == 0) return(1);
	for (int i = A; i > 0; i--)
		Af *= i;
	return(Af);
}
