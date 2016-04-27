//  main.c
//  sort_v2
//
//  Created by Ryzhenkov Serhii on 21/04/16.
//  Copyright © 2016 Ryzhenkov Serhii. All rights reserved.


#include <stdio.h>
#include "Sorting.h"

void printArray(int anArray[], int aSize);
int *CreateArray(int Size);

int main()
{
	/*int sizeArray;
	printf("SizeArray:  %d \n", sizeArray);
	scanf("Size = %d \n", &sizeArray);
	printf("SizeArray: %d \n", sizeArray);
	*/


	int arrSize;
	FILE * ptr = fopen("Plot.csv", "w+");
	fclose(ptr);
	while (1)
		{
			//—читывание слова
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

