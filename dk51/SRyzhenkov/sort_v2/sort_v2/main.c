//  main.c
//  sort_v2
//
//  Created by Ryzhenkov Serhii on 21/04/16.
//  Copyright � 2016 Ryzhenkov Serhii. All rights reserved.


#include <stdio.h>
#include "Sorting.h"
#include <Windows.h>


int *CreateArray(int Size);

int main(int argc, char* argv[])
{
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("� ������ ��������� � ��� ���� ����������� ��������\n������� ������� �� ���������� �������� � ������ ����������� ������,\n������� ������ ����������.");
	printf("\n���������� ����������� 5� ������:\n1) ���������� ���������\n2) ���������� �������\n3) ���������� ��������\n4) ���������� �����\n5) ������� ���������� v1 i v2");
	printf("\n��� �������� ��� ���������� 4 ������ �������:\n1) ����� 500 ���������\n2) ����� 1000 ���������\n3) ����� 5000 ���������\n4) ����� 10000 ���������");
	printf("\n��� ���������� ��������� ���������� ���������,\n������� �� ��������������� ������� ����� ����������,\n���� �� ������ ����� �� ���������, ������� ������� 5.\n");


	int arrSize;
	FILE * ptr = fopen("Plot.csv", "w+");
	fclose(ptr);
	while (1){

	scanf("%i", &arrSize);
	switch (arrSize)
	{
	case 1:
		Sorting_500();
		break;
	case 2:
		Sorting_1000();
		break;
	case 3:
		Sorting_5000();
		break;
	case 4:
		Sorting_10000();
		break;
	case 5:
		exit(0);
		break;
	}
	}
	return 0;
	system("pause");
}

#pragma mark -

int *CreateArray(int size) {
	srand(time(NULL));
	int *anArray = (int *)malloc(sizeof(int)*size);
	for (int i = 0; i<size; i++) {
		*(anArray + i) = rand() % 1000;
	}
	return anArray;
}


