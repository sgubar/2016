// HW2.1.cpp: определяет точку входа для консольного приложения.
// Copyright by Olexandr Vlasenko.

#include "stdafx.h"
#include <iostream>
#include <ctime>

using namespace std;

int N, indx, value;

void ValueAtIndex(int*dynarraytmp)
{
	dynarraytmp[indx-1] = value;
}

int main()
{
	int answer;
	cout << "Enter the size of array: ";
	cin >> N;
	int *dynarray = new int[N];
	srand(time(0));
	for (indx = 0; indx < N; indx++)
		dynarray[indx] = (rand() % 10 + 1);
	cout << "Your array is:" << endl;
	for (indx = 0; indx < N; indx++)
		cout << dynarray[indx] << endl;
	cout << "Do you want to write a value at index? (write 0 or 1)" << endl;
	cin >> answer;
	if (answer == 1)
	{
		cout << "Write an index: ";
		cin >> indx;
		cout << "Enter a value: ";
		cin >> value;
		ValueAtIndex(dynarray);
		cout << "An updated array:" << endl;
		for (indx = 0; indx < N; indx++)
			cout << dynarray[indx] << endl;
	}
	else
		cout << "As you wish :(" << endl;
	delete[] dynarray;
	cout << endl;
	system("pause");
    return 0;
}