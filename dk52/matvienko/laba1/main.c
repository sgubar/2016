#include <stdio.h>
#include <conio.h>
#include "enter1.h"
#include "faktor.h"
#include "output1.h"
#include "modul.h"


int main()
{
	int A, B;
	float Q;
	enter1(&A, &B);
	Q = faktor(A) / modul(2 * A + B);
	output1(Q);
	_getch();
	return 0;
}


