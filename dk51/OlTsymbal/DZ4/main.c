//
//  main.c
//  demoFind
//
//  Created by Olexandr Tsymbal on 08/06/16.
//  Copyright © 2016 OlTsymbal. All rights reserved.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "ordArray.h"
#include "find.h"

#define ARR_SIZE1 (500)
#define ARR_SIZE2 (10000)
#define ARR_SIZE3 (100000)

int main()
{
	int choise = 0;
	ordArrayPtr theArray;
	//clock_t start1, end1, start2, end2;
	/*ordArrayPtr theArray = oa_create(5000);
	int theArray1[5000];
	srand(0);
	for (int i = 0; i < 5000; i++)
	{
		oa_insert(theArray, rand() % 10);
		theArray1[i] = rand() % 10 ;
	}*/
	while (1)
	{
		printf("choise array size\n 1)%d\n 2)%d\n 3)%d\n exit 0\n", ARR_SIZE1, ARR_SIZE2, ARR_SIZE3);
		scanf("%d", &choise);
		switch (choise)
		{
		case 1:
			theArray = oa_create(ARR_SIZE1);
			int theArray1[ARR_SIZE1];
			clock_t start1, end1, start2, end2;
			srand(time(NULL));
			for (int i = 0; i < ARR_SIZE1; i++)
			{
				oa_insert(theArray, rand() % 10);
				theArray1[i] = rand() % 10;
			}
			start1 = clock();
			unsigned theIndex1 = oa_find(theArray, 3);
			end1 = clock();
			printf("Time of binary search of %d elements = [%.100f]", ARR_SIZE1, (long double)(end1 - start1) / CLOCKS_PER_SEC);
			printf("\ntheIndex: %d\n", theIndex1);

			start2 = clock();
			unsigned theIndexLine1 = line_find(theArray1, ARR_SIZE1, 8);
			end2 = clock();
			printf("Time of line search of %d elements = [%.100f]",ARR_SIZE1, (long double)(end2 - start2) / CLOCKS_PER_SEC);
			//printf("Time of start = %.15f", start2/CLOCKS_PER_SEC);
			printf("\ntheIndex of Line find = [%d]\n", theIndexLine1);
			oa_destroy(theArray);
			break;
		case 2:
			theArray = oa_create(ARR_SIZE2);
			int theArray2[ARR_SIZE2];
			clock_t start3, end3, start4, end4;
			srand(time(NULL));
			for (int i = 0; i < ARR_SIZE2; i++)
			{
				oa_insert(theArray, rand() % 10);
				theArray2[i] = rand() % 10;
			}
			/*oa_print(theArray);
			printf("\n\n\n");
			PrintArray(theArray2, ARR_SIZE2);*/
			start3 = clock();
			unsigned theIndex2 = oa_find(theArray, 3);
			end3 = clock();
			printf("Time of binary search of %d elements = [%.100f]", ARR_SIZE2, (long double)(end3 - start3) / CLOCKS_PER_SEC);
			printf("\ntheIndex: %d\n", theIndex2);

			start4 = clock();
			unsigned theIndexLine2 = line_find(theArray2, ARR_SIZE2, 8);
			end4 = clock();
			printf("Time of line search of %d elements = [%.100f]", ARR_SIZE2, (long double)(end4 - start4) / CLOCKS_PER_SEC);
			printf("\ntheIndex of Line find = [%d]\n", theIndexLine2);
			oa_destroy(theArray);
			break;
		case 3:
			theArray = oa_create(ARR_SIZE3);
			int theArray3[ARR_SIZE3];
			clock_t start5, end5, start6, end6;
			srand(time(NULL));
			for (int i = 0; i < ARR_SIZE3; i++)
			{
				oa_insert(theArray, rand() % 10);
				theArray3[i] = rand() % 10;
			}
			start5 = clock();
			unsigned theIndex3 = oa_find(theArray, 3);
			end5 = clock();
			printf("Time of binary search of %d elements = [%.100f]",ARR_SIZE3, (long double)(end5 - start5) / CLOCKS_PER_SEC);
			printf("\ntheIndex: %d\n", theIndex3);

			start6 = clock();
			unsigned theIndexLine3 = line_find(theArray3, ARR_SIZE3, 8);
			end6 = clock();
			printf("Time of line search of %d elements = [%.100f]",ARR_SIZE3, (long double)(end6 - start6) / CLOCKS_PER_SEC);
			printf("\ntheIndex of Line = [%d]\n", theIndexLine3);
			oa_destroy(theArray);
			break;
		case 0:
			exit(0);
			break;
		default:
			printf("Error! Try again\n");
			break;
		}

	}
    //oa_print(theArray);
	//PrintArray(theArray1, 5000);

	

	/*start1 = clock();
	unsigned theIndex = oa_find(theArray, 3 );
	end1 = clock();
	printf("Time of binary search = [%d]", (double)(end1 - start1) / CLOCKS_PER_SEC);
	printf("\ntheIndex: %d\n", theIndex);

	start2 = clock();
	unsigned theIndexLine = line_find(theArray1, 5000, 8);
	end2 = clock();
	printf("Time of line search = [%d]", (double)(end2 - start2) / CLOCKS_PER_SEC);
	printf("\ntheIndex of Line find = [%d]\n", theIndexLine);*/

	system("pause");
	
}
