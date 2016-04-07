																																	// Copyright by Olexandr Vlasenko.

#include "stdafx.h"
#include <iostream>
#include <ctime>

using namespace std;

int N, indx, value;

// The function of outputting the array.
void Output(int*dynarray)
{
	cout << "An updated array:" << endl;
	for (indx = 0; indx < N; indx++)
		cout << dynarray[indx] << "\t";
	cout << endl;
}

// The function of writing value at index.
void ValueAtIndex(int*dynarraytmp)
{
	dynarraytmp[indx-1] = value;
}

// The function of adding elements.
void AddElement(int*dynarraytmp)
{
	int target_indx, target_value;
	cout << "Write an index: ";
	cin >> target_indx;
	cout << "Enter a value: ";
	cin >> target_value;

	for (int i = N++; i >= target_indx; i--)
		dynarraytmp[i] = dynarraytmp[i - 1];
	dynarraytmp[target_indx - 1] = target_value;
}

int main()
{
	int answer = 1;
	cout << "Enter the size of array: ";
	cin >> N;
	int *dynarray = new int[N];

	// Writing randomized values to dynamic array.
	srand(time(0));
	cout << "Your array is:" << endl;
	for (indx = 0; indx < N; indx++)
	{
		dynarray[indx] = (rand() % 10 + 1);
		cout << dynarray[indx] << "\t";
	}
	cout << endl;

	// Block of writing value at index.
	while (answer)
	{
		cout << "Do you want to write a value at index? (write 0 or 1)" << endl;
		cin >> answer;
		if (answer == 0)
			break;
		cout << "Write an index: ";
		cin >> indx;
		cout << "Enter a value: ";
		cin >> value;
		ValueAtIndex(dynarray);
		Output(dynarray);
	}
		cout << "As you wish :(" << endl;

	answer = 1;

	// Block of adding elements.
	while (answer)
	{
		cout << "Do you want to enter an element? (write 0 or 1)" << endl;
		cin >> answer;
		if (answer == 0)
			break;
		AddElement(dynarray);
		Output(dynarray);
	}
		cout << "As you wish :(" << endl;

	delete[] dynarray;
	cout << endl;
	system("pause");
    return 0;
}