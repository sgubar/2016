#define _CRT_SECURE_NO_WARNINGS
#define SIZE_ARRAY_1 (500)
#define SIZE_ARRAY_2 (1000)
#define SIZE_ARRAY_3 (10000)
#define SIZE_ARRAY_4 (40000)
#include"Sorting.h"
#include <time.h>
#include <stdio.h>

int *CreateArray(int aSize);
extern int state = 0;
void Sort1()
{
A:;
	int *anArray = CreateArray(SIZE_ARRAY_1);
	int Array1[SIZE_ARRAY_1];
	int Array2[SIZE_ARRAY_1];
	int Array3[SIZE_ARRAY_1];
	int Array4[SIZE_ARRAY_1];
	int Array5[SIZE_ARRAY_1];
	int Array6[SIZE_ARRAY_1];

	for (int z = 0; z < SIZE_ARRAY_1; z++) {
		Array1[z] = anArray[z];
		Array2[z] = anArray[z];
		Array3[z] = anArray[z];
		Array4[z] = anArray[z];
		Array5[z] = anArray[z];
		Array6[z] = anArray[z];
	}
	while (1)
	{
		printf("Choice method of sorting\n 1)bubble\n 2)selection\n 3)insert\n 4)shellSorting\n 5)Quicksorting V1\n 6)Quicksorting V2\n 7)to refresh an array\n exit 0\n");
		printf("You can choice one method only once\n");
		printf("Put corresponding button ");
		int a = 0;
		clock_t start5, end5, start6, end6;
		scanf("%i", &a);
		switch (a)
		{
		case 1:
			bubbleSort(Array1, SIZE_ARRAY_1);
			break;
		case 2:
			selectionSort(Array2, SIZE_ARRAY_1);
			break;
		case 3:
			insertionSort(Array3, SIZE_ARRAY_1);
			break;
		case 4:
			shellSort(Array4, SIZE_ARRAY_1);
			break;
		case 5:
			start5 = clock();
			quickSort(Array5, 0, SIZE_ARRAY_1 - 1);
			end5 = clock();
			//printf("Time of start = %.15f", start5);
			//printf("Time of End = %.15f", end5);
			printf("Time of Quick sorting v1 = %.15f\n", (double)(end5 - start5) / CLOCKS_PER_SEC);
			break;
		case 6:
			start6 = clock();
			quickSort_v2(Array6, 0, SIZE_ARRAY_1 - 1);
			end6 = clock();
			//printf("Time of start = %.15f", start6);
			//printf("Time of End = %.15f", end6);
			printf("Time of Quick sorting v1 = %.15f\n", (double)(end6-start6)/CLOCKS_PER_SEC);
			break;
		case 7:
			free(anArray);
			goto A;
			break;
		case 0:
			state=1;
			break;
		default:
			printf("Uncorrect choice, Please try again\n");
			break;
		}
		if (state == 1) break;
	}
	state = 0;
}

void Sort2()
{
A:;
	int *anArray = CreateArray(SIZE_ARRAY_2);
	int Array1[SIZE_ARRAY_2];
	int Array2[SIZE_ARRAY_2];
	int Array3[SIZE_ARRAY_2];
	int Array4[SIZE_ARRAY_2];
	int Array5[SIZE_ARRAY_2];
	int Array6[SIZE_ARRAY_2];

	for (int z = 0; z < SIZE_ARRAY_2; z++) {
		Array1[z] = anArray[z];
		Array2[z] = anArray[z];
		Array3[z] = anArray[z];
		Array4[z] = anArray[z];
		Array5[z] = anArray[z];
		Array6[z] = anArray[z];
	}
	while (1)
	{
		printf("Choice method of sorting\n 1)bubble\n 2)selection\n 3)insert\n 4)shellSorting\n 5)Quicksorting V1\n 6)Quicksorting V2\n 7)to refresh an array\n exit 0\n");
		printf("You can choice one method only once\n");
		printf("Put corresponding button ");
		int a = 0;
		clock_t start5, end5, start6, end6;
		scanf("%i", &a);
		switch (a)
		{
		case 1:
			bubbleSort(Array1, SIZE_ARRAY_2);
			break;
		case 2:
			selectionSort(Array2, SIZE_ARRAY_2);
			break;
		case 3:
			insertionSort(Array3, SIZE_ARRAY_2);
			break;
		case 4:
			shellSort(Array4, SIZE_ARRAY_2);
			break;
		case 5:
			start5 = clock();
			quickSort(Array5, 0, SIZE_ARRAY_2 - 1);
			end5 = clock();
			//printf("Time of start = %.15f", start5);
			//printf("Time of End = %.15f", end5);
			printf("Time of Quick sorting v1 = %.15f\n", (double)(end5 - start5) / CLOCKS_PER_SEC);
			break;
		case 6:
			start6 = clock();
			quickSort_v2(Array6, 0, SIZE_ARRAY_2 - 1);
			end6 = clock();
			//printf("Time of start = %.15f", start6);
			//printf("Time of End = %.15f", end6);
			printf("Time of Quick sorting v1 = %.15f\n", (double)(end6 - start6) / CLOCKS_PER_SEC);
			break;
		case 7:
			free(anArray);
			goto A;
			break;
		case 0:
			state=1;
			break;
		default:
			printf("Uncorrect choice, Please try again\n");
			break;
		}
		if (state == 1) break;
	}
	state = 0;
}

void Sort3()
{
A:;
	int *anArray = CreateArray(SIZE_ARRAY_3);
	int Array1[SIZE_ARRAY_3];
	int Array2[SIZE_ARRAY_3];
	int Array3[SIZE_ARRAY_3];
	int Array4[SIZE_ARRAY_3];
	int Array5[SIZE_ARRAY_3];
	int Array6[SIZE_ARRAY_3];

	for (int z = 0; z < SIZE_ARRAY_3; z++) {
		Array1[z] = anArray[z];
		Array2[z] = anArray[z];
		Array3[z] = anArray[z];
		Array4[z] = anArray[z];
		Array5[z] = anArray[z];
		Array6[z] = anArray[z];
	}
	while (1)
	{
		printf("Choice method of sorting\n 1)bubble\n 2)selection\n 3)insert\n 4)shellSorting\n 5)Quicksorting V1\n 6)Quicksorting V2\n 7)to refresh an array\n exit 0\n");
		printf("You can choice one method only once\n");
		printf("Put corresponding button ");
		int a = 0;
		clock_t start5, end5, start6, end6;
		scanf("%i", &a);
		switch (a)
		{
		case 1:
			bubbleSort(Array1, SIZE_ARRAY_3);
			break;
		case 2:
			selectionSort(Array2, SIZE_ARRAY_3);
			break;
		case 3:
			insertionSort(Array3, SIZE_ARRAY_3);
			break;
		case 4:
			shellSort(Array4, SIZE_ARRAY_3);
			break;
		case 5:
			start5 = clock();
			quickSort(Array5, 0, SIZE_ARRAY_3 - 1);
			end5 = clock();
			//printf("Time of start = %.15f", start5);
			//printf("Time of End = %.15f", end5);
			printf("Time of Quick sorting v1 = %.15f\n", (double)(end5 - start5) / CLOCKS_PER_SEC);
			break;
		case 6:
			start6 = clock();
			quickSort_v2(Array6, 0, SIZE_ARRAY_3 - 1);
			end6 = clock();
			//printf("Time of start = %.15f", start6);
			//printf("Time of End = %.15f", end6);
			printf("Time of Quick sorting v1 = %.15f\n", (double)(end6 - start6) / CLOCKS_PER_SEC);
			break;
		case 7:
			free(anArray);
			goto A;
			break;
		case 0:
			state = 1;
			break;
		default:
			printf("Uncorrect choice, Please try again\n");
			break;
		}
		if (state == 1) break;
	}
	state = 0;
}

void Sort4()
{
A:;
	int *anArray = CreateArray(SIZE_ARRAY_4);
	int Array1[SIZE_ARRAY_4];
	int Array2[SIZE_ARRAY_4];
	int Array3[SIZE_ARRAY_4];
	int Array4[SIZE_ARRAY_4];
	int Array5[SIZE_ARRAY_4];
	int Array6[SIZE_ARRAY_4];

	for (int z = 0; z < SIZE_ARRAY_4; z++) {
		Array1[z] = anArray[z];
		Array2[z] = anArray[z];
		Array3[z] = anArray[z];
		Array4[z] = anArray[z];
		Array5[z] = anArray[z];
		Array6[z] = anArray[z];
	}
	while (1)
	{
		printf("Choice method of sorting\n 1)bubble\n 2)selection\n 3)insert\n 4)shellSorting\n 5)Quicksorting V1\n 6)Quicksorting V2\n 7)to refresh an array\n exit 0\n");
		printf("You can choice one method only once\n");
		printf("Put corresponding button ");
		int a = 0;
		clock_t start5, end5, start6, end6;
		scanf("%i", &a);
		switch (a)
		{
		case 1:
			bubbleSort(Array1, SIZE_ARRAY_4);
			break;
		case 2:
			selectionSort(Array2, SIZE_ARRAY_4);
			break;
		case 3:
			insertionSort(Array3, SIZE_ARRAY_4);
			break;
		case 4:
			shellSort(Array4, SIZE_ARRAY_4);
			break;
		case 5:
		    start5 = clock();
			quickSort(Array5, 0, SIZE_ARRAY_4 - 1);
			end5 = clock();
			//printf("Time of start = %.15f", start5);
			//printf("Time of End = %.15f", end5);
			printf("Time of Quick sorting v1 = %.15f\n", (double)(end5 - start5) / CLOCKS_PER_SEC);
			break;
		case 6:
			start6 = clock();
			quickSort_v2(Array6, 0, SIZE_ARRAY_4 - 1);
			end6 = clock();
			//printf("Time of start = %.15f", start6);
			//printf("Time of End = %.15f", end6);
			printf("Time of Quick sorting v1 = %.15f\n", (double)(end6 - start6) / CLOCKS_PER_SEC);
			break;
		case 0:
			state = 1;
			break;
		case 7:
			free(anArray);
			goto A;
			break;
		default:
			printf("Uncorrect choice, Please try again\n");
			break;
		}
		if (state == 1) break;
	}
	state = 0;
}

int *CreateArray(int aSize) {

    srand(time(NULL));
	int *anArray = (int *)malloc(sizeof(int)*aSize);
	for (int i = 0; i<aSize; i++) {
		*(anArray + i) = rand() % 100;
	}
	return anArray;
}
