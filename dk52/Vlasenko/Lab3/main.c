#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "SimpleSort.h"
#include "ShellSort.h"
#include "QuickSort.h"

void printArray(int Array[], int N)		// The function of printing array
{
	int i;
	printf("{ ");
	for (i = 0; i < N; i++)
	{
		printf("%d ", Array[i]);
	}

	printf("}\n");
}

void fillArray(int Array[], int N)		// The function of filling randomized values to array
{
	int i;
	srand(time(NULL));
	for (i = 0; i < N; i++)
	{
		Array[i] = rand() % 1001;
	}
}

int main(int argc, char *argv[])
{
	int N=9999, i;
	unsigned int start_time, end_time;
	int Array1[N], Array2[N], Array3[N], Array4[N], Array5[N];
	
	
	fillArray(Array1, N);	// Filling randomized values to array
	printArray(Array1, N);	// Printing array
	
	for (i=0;i<N;i++)		// Copying the fist array to the second, third, fourth and fifth
	{
		Array2[i]=Array1[i];
		Array3[i]=Array1[i];
		Array4[i]=Array1[i];
		Array5[i]=Array1[i];
	}
	
	// Working with BubbleSorting
	start_time =  clock();	// Getting the time of start function
	bubbleSort(Array1,N);	// Doing function
	end_time = clock();		// Getting the time of end function
	double BubbleTime=(double)(end_time - start_time)/CLOCKS_PER_SEC;	// Calculating the work time
	printArray(Array1, N);	// Printing sorted array
	
	// Working with SelectionSorting
	start_time =  clock();
	selectionSort(Array2,N);
	end_time = clock();
	double SelectionTime=(double)(end_time - start_time)/CLOCKS_PER_SEC;
	printArray(Array2, N);
	
	// Working with InsertionSorting
	start_time =  clock();
	insertionSort(Array3,N);
	end_time = clock();
	double InsertionTime=(double)(end_time - start_time)/CLOCKS_PER_SEC;
	printArray(Array3, N);
	
	// Working with ShellSorting
	start_time =  clock();
	ShellSort(Array4,N);
	end_time = clock();
	double ShellTime=(double)(end_time - start_time)/CLOCKS_PER_SEC;
	printArray(Array4, N);
	
	// Working with QuickSorting
	start_time =  clock();
	ShellSort(Array5,N);
	end_time = clock();
	double QuickTime=(double)(end_time - start_time)/CLOCKS_PER_SEC;
	printArray(Array5, N);
	
	// Printing the times of working with functions of sorting
	printf ("\n");
	printf ("Time of Bubble sorting: %.5lf\n", BubbleTime);
	printf ("Time of Selection sorting: %.5lf\n", SelectionTime);
	printf ("Time of Insertion sorting: %.5lf\n", InsertionTime);
	printf ("Time of Shell sorting: %.5lf\n", ShellTime);
	printf ("Time of Quick sorting: %.5lf\n", QuickTime);
	
	
	return 0;
}
