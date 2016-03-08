// lab1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <math.h>

#include "stepan.h"
#include "stepan2.h"
#include "module.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	float A, B, C, Q, Q1, Q2, U;
	Q2 = 0;
	cout << "Введите значение А: ";
	cin >> A;
	cout << "Введите значение B: ";
	cin >> B;
	cout << "Введите значение C (не может быть нулем): ";
	cin >> C;
	if (C == 0)
	{
		cout << "Я же сказал С не может быть нулем! Ошибка." << endl;
		system("pause");
		return 0;
	}	
	else
	{
		U = A*C - B;
		Q1 = module(U) / stepan(C);
	}
	for (int i = 0; i <= A; i++)
	{
		Q2 =  Q2 + stepan2(i);
	}
	Q = Q1 * Q2;
	cout << "Результат общитаной формулы: " << Q << endl;
	system("pause");
    return 0;
}