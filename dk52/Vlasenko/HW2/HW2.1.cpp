																																	// Copyright by Olexandr Vlasenko.

#include "stdafx.h"
#include <iostream>
#include <ctime>

using namespace std;

int N, indx, target_indx, value, target_value;

// The function of writing value at index.
void ValueAtIndex(int*dynarraytmp)
{
	dynarraytmp[indx-1] = value;
}

// The function of adding elements.
/*void AddElement(int*dynarraytmp)
{
	int *dynarray2 = new int[N+1];
	for (indx = 0; indx < target_indx; indx++)
		dynarray2[indx] = dynarraytmp[indx];
	dynarray2[target_indx] = target_value;
	for (indx = target_indx; indx < N; indx++)
		dynarray2[indx] = dynarraytmp[indx];
}*/

int main()
{
	int answer;
	cout << "Enter the size of array: ";
	cin >> N;
	int *dynarray = new int[N];
	// Writing randomized values to dynamic array.
	srand(time(0));
	for (indx = 0; indx < N; indx++)
		dynarray[indx] = (rand() % 10 + 1);
	cout << "Your array is:" << endl;
	for (indx = 0; indx < N; indx++)
		cout << dynarray[indx] << endl;

	// Block of writing value at index.
	block1:
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
		goto block1;
	}
	else
		cout << "As you wish :(" << endl;

	// Block of adding elements.
	block2:
	cout << "Do you want to enter an element? (write 0 or 1)" << endl;
	cin >> answer;
	if (answer == 1)
	{
		
		cout << "Write an index: ";
		cin >> target_indx;
		cout << "Enter a value: ";
		cin >> target_value;

		int *dynarray2 = new int[N + 1];
		for (indx = 0; indx < N; indx++)
			dynarray2[indx] = 0;

		for (indx = 0; indx < target_indx; indx++)
			dynarray2[indx] = dynarray[indx];
		dynarray2[target_indx] = target_value;
		for (indx = target_indx; indx < N; indx++)
			dynarray2[indx] = dynarray[indx];

		cout << "An updated array:" << endl;
		for (indx = 0; indx < N; indx++)
			cout << dynarray2[indx] << endl;
		goto block2;
	}
	else
		cout << "As you wish :(" << endl;
	delete[] dynarray;
	delete[] dynarray2;
	cout << endl;
	system("pause");
    return 0;
}