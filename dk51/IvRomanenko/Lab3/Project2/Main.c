#include <stdio.h>
#include <time.h>
#include "Sorting.h"
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))
int main(int argc, const char * argv[])
{
	int theArray[10000];
	int theArray1[10000];
	int theArray2[10000];
	int theArray3[10000];
	clock_t time, time2, time3, time1;
	for (int i = 0; i < 10000; i++)
	{
		theArray[i] = rand();
		theArray2[i] = theArray[i];
		theArray3[i] = theArray[i];
		theArray1[i] = theArray[i];
	}
	time = clock();
	bubbleSort(theArray, ARRAY_SIZE(theArray));
	time = clock() - time;
	printf("Time of buble sorting = %f\n", (double)time / CLOCKS_PER_SEC);
	time2 = clock();
	selectionSort(theArray1, ARRAY_SIZE(theArray1));
	time2 = clock() - time2;
	printf("Selection sort time %f\n", (double)time2 / CLOCKS_PER_SEC);
	time3 = clock();
	insertionSort(theArray2, ARRAY_SIZE(theArray2));
	time3 = clock() - time3;
	printf("Insertion Sort %f\n", (double)time2 / CLOCKS_PER_SEC);
	time1 = clock();
	shellSort(theArray3, ARRAY_SIZE(theArray3));
	time1 = clock() - time1;
	printf("Shell sort %f\n", (double)time1 / CLOCKS_PER_SEC);
	system("pause");
	return 0;
}