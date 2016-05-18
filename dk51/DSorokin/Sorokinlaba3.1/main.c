//
//  main.c
//  demoSimpleSort
//
//  Created by Slava Gubar on 4/7/16.
//  Copyright © 2016 Slava Gubar. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include "Simple.h"
#include "Shell.h"
#include "quiq.h"


#define ARRAY_SIZE(a) (sizeof(theArray)/sizeof(theArray[0]))//определяем макрос

int main(int argc, const char * argv[])
{
	int theArrayS[50000];//декларируем масивы 
	int theArrayQ[50000];
	int theArraySH[50000];
	int theArray[50000];

	srand(time(NULL));//Обнуляем время 
	for (int i = 0; i < 50000; i++)//Заполняем массивы
	{
		theArray[i] = rand();
		theArrayS[i] = theArray[i];
		theArraySH[i] = theArray[i];
		theArrayQ[i] = theArray[i];
	}

	printf("Test bubble sorting\n");
	clock_t theStart2 = clock();// Возвращает количество временных тактов, прошедших с начала запуска программы.
	bubbleSort(theArrayS, ARRAY_SIZE(theArrayS));
	clock_t theEnd2 = clock();// Возвращает количество временных тактов, прошедших с начала запуска сортировки.
	printf("time of bubble sorting: %.15lf\n", (double)(theEnd2 - theStart2) / CLOCKS_PER_SEC);//Превращаем тики в секунды

	printf("\nTest selection sorting\n");

	clock_t theStart1 = clock();
	selectionSort(theArrayS, ARRAY_SIZE(theArrayS));
	clock_t theEnd1 = clock();
	printf("time of selection sorting: %.15lf\n", (double)(theEnd1 - theStart1) / CLOCKS_PER_SEC);

	printf("\nTest insertion sorting\n");

	clock_t theStart0 = clock();
	insertionSort(theArrayS, ARRAY_SIZE(theArrayS));
	clock_t theEnd0 = clock();
	printf("time of insertion sorting: %.15lf\n", (double)(theEnd0 - theStart0) / CLOCKS_PER_SEC);

	printf("\nTest Shell sorting\n");

	clock_t theStart = clock();
	shellSort(theArraySH, ARRAY_SIZE(theArraySH));
	clock_t theEnd = clock();

	printf("time of Shell sorting: %.15lf\n", (double)(theEnd - theStart) / CLOCKS_PER_SEC);


	printf("\nTest Quick sorting\n");

	clock_t theStart3 = clock();
	quickSort(theArrayQ, 0 , 50000);
	clock_t theEnd3 = clock();

	printf("time of Quick sorting: %.15lf\n", (double)(theEnd3 - theStart3) / CLOCKS_PER_SEC);

	system("pause");
	return 0;

}

