//  main.c
//  sort_v2
//
//  Created by Ryzhenkov Serhii on 21/04/16.
//  Copyright © 2016 Ryzhenkov Serhii. All rights reserved.


#include <stdio.h>
#include "Sorting.h"
#include <Windows.h>

void printArray(int anArray[], int aSize);
int *CreateArray(int Size);

int main(int argc, char* argv[])
{
	/*int sizeArray;
	printf("SizeArray:  %d \n", sizeArray);
	scanf("Size = %d \n", &sizeArray);
	printf("SizeArray: %d \n", sizeArray);
	*/
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("Добро пожаловать!!\n");
	printf("В данной программе у вас есть возможность сравнить\nзатраты времени на сортировку массивов с разным количеством данных,\nразными видами сортировок.");
	printf("\nСортировка выполняется 5ю видами:\n1) Сортировка пузырьком\n2) Сортировка выбором\n3) Сортировка вставкой\n4) Сортировка Шелла\n5) Быстрая сортировка(Приносим свои извинения, на данный момент не доступна,\nнаходится на стадии разработки)");
	printf("\nВам доступны для сравненния 4 разных массива:\n1) Имеет 500 элементов\n2) Имеет 1000 элементов\n3) Имеет 5000 элементов\n4) Имеет 10000 элементов");
	printf("\nДля сортировки желаемого количества элементов,\nнажмите на соответствующую клавишу вашей клавиатуры,\nесли вы хотите выйти из программы, нажмите клавишу 5.\n");
	printf("\nБлагодарим вас, за использование нашей программы.\n");

	int arrSize;
	FILE * ptr = fopen("Plot.csv", "w+");
	fclose(ptr);
	while (1)
		{
			//Считывание слова
			//обработка
			//проверка выхода
			//и т.д.
	
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
	//	printf("\nБлагодарим вас, за использование нашей программы.\n");
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

void printArray(int anArray[], int aSize)
{
	printf("{");
	for (int i = 0; i < aSize; i++)
	{
		printf(" %d ", anArray[i]);
	}

	printf("}\n");
}

