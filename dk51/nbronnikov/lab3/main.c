//
//  Lab3
// 
//
//  Created by Nazar Bronnikov on 15/05/16.
//  Copyright (C) 2016 Nazar Bronnikov. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>


#include "SimpleSort.h"
#include "shellSort.h"
#include "quickSort.h"

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))

static void printArray(int anArray[], int aSize);
static void fillArray(int anArray[], int aSize, int aPivot);
static void show_menu(int *choise);

int main(int argc, const char * argv[])
{
	int sort_type = -1;
	int exit = 0;
	int array_size = 0;

	while (!exit)
	{
		show_menu(&sort_type);

		switch (sort_type)
		{
			case 1:
			{
				printf("Vvedite razmer massiva:  ");

				scanf_s("%d%*[^\n]", &array_size);

				int *array_ptr = (int*)malloc(array_size * sizeof(int));

				fillArray(array_ptr, array_size, 9999);

				clock_t start = clock();
				bubbleSort(array_ptr, array_size);
				clock_t end = clock();

				free(array_ptr);
				
				printf ("Vremya sortirovki: %.10lf\n", (double)(end - start)/CLOCKS_PER_SEC);
			}
			break;

			case 2:
			{
				printf("Vvedite razmer massiva:  ");

				scanf_s("%d%*[^\n]", &array_size);

				int *array_ptr = (int*)malloc(array_size * sizeof(int));

				fillArray(array_ptr, array_size, 9999);

				clock_t start = clock();
				selectionSort(array_ptr, array_size);
				clock_t end = clock();

				free(array_ptr);
				
				printf ("Vremya sortirovki: %.10lf\n", (double)(end - start)/CLOCKS_PER_SEC);
			}
			break;

			case 3:
			{
				printf("Vvedite razmer massiva:  ");

				scanf_s("%d%*[^\n]", &array_size);

				int *array_ptr = (int*)malloc(array_size * sizeof(int));

				fillArray(array_ptr, array_size, 9999);

				clock_t start = clock();
				insertionSort(array_ptr, array_size);
				clock_t end = clock();

				free(array_ptr);
				
				printf ("Vremya sortirovki: %.10lf\n", (double)(end - start)/CLOCKS_PER_SEC);
			}
			break;

			case 4:
			{
				printf("Vvedite razmer massiva:  ");

				scanf_s("%d%*[^\n]", &array_size);

				int *array_ptr = (int*)malloc(array_size * sizeof(int));

				fillArray(array_ptr, array_size, 9999);

				clock_t start = clock();
				shellSort(array_ptr, array_size);
				clock_t end = clock();

				free(array_ptr);
				
				printf ("Vremya sortirovki: %.10lf\n", (double)(end - start)/CLOCKS_PER_SEC);
			}
			break;

			case 5:
			{
				printf("Vvedite razmer massiva:  ");

				scanf_s("%d%*[^\n]", &array_size);

				int *array_ptr = (int*)malloc(array_size * sizeof(int));

				fillArray(array_ptr, array_size, 9999);

				clock_t start = clock();
				quickSort(array_ptr, 0, array_size - 1);
				clock_t end = clock();

				free(array_ptr);
				
				printf ("Vremya sortirovki: %.10lf\n", (double)(end - start)/CLOCKS_PER_SEC);
			}
			break;

			case 6:
			{
				printf("Vvedite razmer massiva:  ");

				scanf_s("%d%*[^\n]", &array_size);

				int *array_ptr = (int*)malloc(array_size * sizeof(int));

				fillArray(array_ptr, array_size, 9999);

				clock_t start = clock();
				quickSort2(array_ptr, 0, array_size - 1);
				clock_t end = clock();

				free(array_ptr);
				
				printf ("Vremya sortirovki: %.10lf\n", (double)(end - start)/CLOCKS_PER_SEC);
			}
			break;

			case 9:
			{
				exit = 1;
			}
			break;

			default:
				printf("Nevernaya komanda! \n");
			break;
		}

		printf("\n \n \n");
	}
	

	return 0;
}

static void show_menu(int *choise)
{
	printf("Vuberite tip sortirovki: \n");

	printf("\t Pyzurkovaya - 1. \n");
	printf("\t Vuborom - 2. \n");
	printf("\t Vstavkoy - 3. \n");
	printf("\t Shell sortirovka - 4. \n");
	printf("\t Bustraya - 5. \n");
	printf("\t Bustraya 2 - 6. \n");

	printf("\t Vuhod is programmu - 9. \n");

	printf("\n Vash vubor: ");

	scanf_s("%d%*[^\n] ", choise);
}

void fillArray(int anArray[], int aSize, int max_val)
{
	srand(0);

	for (int i = 0; i < aSize; i++)
	{
		anArray[i] = rand() % max_val;
	}
}
