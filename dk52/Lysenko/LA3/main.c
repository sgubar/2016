#include <stdio.h>
#include <time.h>
#include "SimpleSort.h"
#include "shellSort.h"
#include "quickSort.h"

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0])) //Sozdaem makros
static void fillArray(int anArray[], int aSize, int aPivot);
static void printArray(int anArray[], int aSize);


#pragma mark -
void printArray(int anArray[], int aSize)
{
	printf("{");
	for (int i = 0; i < aSize; i++)
	{
		printf(" %d ", anArray[i]);
	}

	printf("}\n");
}

//Random
void fillArray(int anArray[], int aSize, int aPivot)
{
	srand(time(NULL));
	for (int i = 0; i < aSize; i++)
	{
		anArray[i] = rand() % (2 * aPivot);
	}
}



int main(int argc, const char * argv[])
{
	printf("Choose sorting:\n");
	printf("1. Bubble sorting\n");
	printf("2. Selection sorting\n");
	printf("3. Insertion sorting\n");
	printf("4. Shell sorting\n");
	printf("5. Quick sorting\n");
	printf("6. Exit\n");
	printf("\n");

	int operation;
	// Vibiraem operaciyu
	do {
		printf("Enter number of operation:\n");
		scanf_s("%d", &operation);
		printf("\n");
	} while (operation != 1 && operation != 2 && operation != 3 && operation != 4 && operation != 5 && operation != 6);
	if (operation == 1) 
	{
		printf("Test bubble sorting\n");
		int bubbleArray[1000]; //Inizializiruem massiv
		fillArray(bubbleArray, ARRAY_SIZE(bubbleArray), 1000); //Zapolnyaem massiv
		printArray(bubbleArray, ARRAY_SIZE(bubbleArray)); //Vivodim na ekran
		bubbleSort(bubbleArray, ARRAY_SIZE(bubbleArray));//Functsiya sortirovki

		//Vichislyaem vremy vipolneniya sortirovki
		clock_t theStart = clock();
		bubbleSort(bubbleArray, ARRAY_SIZE(bubbleArray));
		clock_t theEnd = clock();
		printArray(bubbleArray, ARRAY_SIZE(bubbleArray));
		printf("Time of Bubble sorting: %.10lf\n", (double)(theEnd - theStart) / CLOCKS_PER_SEC);
	} 
	else if (operation == 2) 
	{
		printf("\nTest selection sorting\n");
		int selectionArray[1000]; //Inizializiruem massiv
		fillArray(selectionArray, ARRAY_SIZE(selectionArray), 1000); //Zapolnyaem massiv
		printArray(selectionArray, ARRAY_SIZE(selectionArray)); //Vivodim na ekran
		selectionSort(selectionArray, ARRAY_SIZE(selectionArray)); //Functsiya sortirovki

		//Vichislyaem vremy vipolneniya sortirovki
		clock_t theStart2 = clock();
		selectionSort(selectionArray, ARRAY_SIZE(selectionArray));
		clock_t theEnd2 = clock();
		printArray(selectionArray, ARRAY_SIZE(selectionArray));
		printf("Time of selection sorting: %.10lf\n", (double)(theEnd2 - theStart2) / CLOCKS_PER_SEC);
	}
	else if (operation == 3) 
	{
		printf("\nTest insertion sorting\n");
		int insertionArray[1000];
		fillArray(insertionArray, ARRAY_SIZE(insertionArray), 1000); //Zapolnyaem massiv
		printArray(insertionArray, ARRAY_SIZE(insertionArray)); //Vivodim na ekran
		insertionSort(insertionArray, ARRAY_SIZE(insertionArray)); //Functsiya sortirovki

		//Vichislyaem vremy vipolneniya sortirovki
		clock_t theStart3 = clock();
		insertionSort(insertionArray, ARRAY_SIZE(insertionArray));
		clock_t theEnd3 = clock();
		printArray(insertionArray, ARRAY_SIZE(insertionArray));
		printf("Time of insertion sorting: %.10lf\n", (double)(theEnd3 - theStart3) / CLOCKS_PER_SEC);
	}
	else if (operation == 4) 
	{
		printf("\nTest Shell sorting\n");
		int ShellArray[1000];
		fillArray(ShellArray, ARRAY_SIZE(ShellArray), 1000); //Zapolnyaem massiv
		printArray(ShellArray, ARRAY_SIZE(ShellArray)); //Vivodim na ekran
		shellSort(ShellArray, ARRAY_SIZE(ShellArray)); //Functsiya sortirovki

		//Vichislyaem vremy vipolneniya sortirovki
		clock_t theStart4 = clock();
		shellSort(ShellArray, ARRAY_SIZE(ShellArray));
		clock_t theEnd4 = clock();
		printArray(ShellArray, ARRAY_SIZE(ShellArray));
		printf("Time of Shell sorting: %.10lf\n", (double)(theEnd4 - theStart4) / CLOCKS_PER_SEC);
	}
	else if (operation == 5) 
	{ 
		printf("\nTest Quick sorting\n");
		int quickArray[1000];
		fillArray(quickArray, ARRAY_SIZE(quickArray), 1000); //Zapolnyaem massiv
		printArray(quickArray, ARRAY_SIZE(quickArray)); //Vivodim na ekran
		quickSort(quickArray, ARRAY_SIZE(quickArray)); //Functsiya sortirovki

		//Vichislyaem vremy vipolneniya sortirovki
		clock_t theStart5 = clock();
		quickSort(quickArray, ARRAY_SIZE(quickArray));
		clock_t theEnd5 = clock();
		printArray(quickArray, ARRAY_SIZE(quickArray));
		printf("Time of Quick sorting: %.10lf\n", (double)(theEnd5 - theStart5) / CLOCKS_PER_SEC);
	}
	else if (operation == 6)
	{
		return(0);
	}

	system("PAUSE"); //Ne daem zakrit consol
	return(0);
}

