/*																 /
/  compare.c			                                         /
/  compare search                                                /
/                                                                /
/  Created by Sergey Ninoshvili on 25/6/16.                      /
/  Copyright © 2016 Sergey Ninoshvili. All rights reserved.      /
/																*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "compare.h"
#include "find.h"
#include "ordArray.h"

int *createArray(int size, int pivot)
{
	int *Array = (int*)malloc(size*sizeof(int));
	int i;

	srand(time(NULL));

	for (i = 0; i < size; i++)
		Array[i] = i + 1;
	return Array;
}

void PArray(int *Array, int size)
{
	printf("{");
	int i;
	for (i = 0; i != size; i++)
		printf(" %d ", Array[i]);
	printf("}\n");
}

void lineSearchRezult()
{
	int size = 10;
	int *Array;
	int key;
	do
	{
		Array = createArray(size, size);

		if (size == 10)
		{
			printf("\ntesting line search\n");
			PArray(Array, size);
		}
		key = Array[size - 1];

		clock_t Start = clock();
		unsigned index = line_find(Array, size, key);
		clock_t Finish = clock();

		printf("\ndata at index %d is %d\n", index, Array[index]);

		printf("time for %5d elements = %43.40llf\n", size, (double)((Finish - Start) / CLOCKS_PER_SEC));

		size = (size == 100000) ? 500000 : (size * 10);
	} while (size < 600000);

	free(Array);
}
void binarySearchRezult()
{
	int size = 10;
	int *Array;
	int key;
	do
	{
		Array = createArray(size, size);

		if (size == 10)
		{
			printf("\ntesting binary search\n");
			PArray(Array, size);
		}
		key = Array[size - 1];

		clock_t Start = clock();
		unsigned index = oa_find(Array, size, key);
		clock_t Finish = clock();

		printf("\ndata at index %d is %d\n", index, Array[index]);

		printf("time for %5d elements = %43.40llf\n", size, (double)((Finish - Start) / CLOCKS_PER_SEC));

		size = (size == 100000) ? 500000 : (size * 10);
	} while (size < 600000);

	free(Array);
}
