#include "stdafx.h"
#include <stdlib.h>
#include <iostream>																		// Connecting librarys
#include <math.h>

#include "module.h"																		// Connecting personal headers
#include "Universal_power.h"

using namespace std;

int main()
{
	float A = 0, B = 0, C = 0, Q = 0, Q1 = 0, Q2 = 0, U = 0; int i = 0;					// Initilazing
	cout << "Enter value of A: ";
	cin >> A;
	cout << "Enter value of B: ";														// Entering values
	cin >> B;
	cout << "Enter value of C (cant be zero): ";
	cin >> C;
	if (C == 0)																			// Checking zero value
	{
		cout << "C=0. Error!" << endl;
		system("pause");
		return 0;
	}
	else																				// Calculating the first part
	{
		U = A*C - B;
		Q1 = module(U) / Universal_power(C, 3);
	}
	for (i = 0; i <= A; i++)															// Calculating the second part
	{
		Q2 =  Q2 + Universal_power(2, i);
	}
	Q = Q1 * Q2;																		// Calculating the result
	cout << "The result is: " << Q << endl;												// Result output
	system("pause");
    return 0;
}
