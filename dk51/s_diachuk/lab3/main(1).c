#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define ARRAY_SIZE(a) (sizeof(theArray)/sizeof(theArray[0]))
#define ArraySize 10000
static void printArray(int anArray[], int aSize);
static void fillArray(int anArray[], int aSize, int aPivot);
static void BubbleSort(int anArray[], int aSize);
static void InsertionSort(int anArray[], int aSize);
static void swap(int anArray[], int aLeftIndex, int aRightIndex);
static int mediana(int anArray[], int aLeftIndex, int aRightIndex);
static int m_partitionIt(int anArray[], int aLeftIndex, int aRightIndex, int aPivot);
static void m_manualSort(int anArray[], int aLeftIndex, int aRightIndex);
static int partitionIt(int anArray[], int aLeftIndex, int aRightIndex, int aPivot);
static void quickSort(int anArray[], int aLeftIndex, int aRightIndex);
static void quickSort2(int anArray[], int aLeftIndex, int aRightIndex);
static void SelectionSort(int anArray[], int aSize);
static void ShellSort(int anArray[], int aCount);


int main(int argc, const char * argv[])
{
	/*..................................................................................................*/

	int theArray[ArraySize];
	int Number;
	int theArray1[ArraySize];
	int theArray2[ArraySize];
	int theArray3[ArraySize];
	int theArray4[ArraySize];
	int theArray5[ArraySize];
    srand(time(NULL));
    for (Number = 0; Number < ArraySize; Number++)
    {
        theArray[Number] = 0 + rand() % ArraySize;
        theArray1[Number]=theArray[Number];
        theArray2[Number]=theArray[Number];
        theArray3[Number]=theArray[Number];
        theArray4[Number]=theArray[Number];
        theArray5[Number]=theArray[Number];
	}

	printf("\nTest bubble sorting\n\n");
//    intArray(theArray1, ARRAY_SIZE(theArray1));
//    printf("\n");
	clock_t theStart1 = clock();
	BubbleSort(theArray1, ARRAY_SIZE(theArray1));
	clock_t theEnd1 = clock();
//    printf("\n");
//	printArray(theArray1, ARRAY_SIZE(theArray4));

/*........................................................................................................*/

	printf("\nTest selection sorting\n\n");

//	printArray(theArray2, ARRAY_SIZE(theArray2));
//    printf("\n");
	clock_t theStart2 = clock();
	SelectionSort(theArray2, ARRAY_SIZE(theArray2));
	clock_t theEnd2 = clock();
//    printf("\n");
//	printArray(theArray2, ARRAY_SIZE(theArray2));

/*........................................................................................................*/

	printf("\nTest insertion sorting\n\n");
//	printArray(theArray3, ARRAY_SIZE(theArray3));
//    printf("\n");
	clock_t theStart3 = clock();
	SelectionSort(theArray3, ARRAY_SIZE(theArray3));
	clock_t theEnd3 = clock();
//    printf("\n");
//	printArray(theArray3, ARRAY_SIZE(theArray3));

/*........................................................................................................*/

	printf("\nTest Shell sorting\n\n");
//	printArray(theArray4, ARRAY_SIZE(theArray4));
//    printf("\n");
    clock_t theStart4 = clock();
	ShellSort(theArray4, ARRAY_SIZE(theArray4));
	clock_t theEnd4 = clock();
//    printf("\n");
//	printArray(theArray4, ARRAY_SIZE(theArray4));

/*........................................................................................................*/

	printf ("\nStart to make partition of the array\n");
	int thePivot = 2500; //make the pivot as avarage VALUE
	fillArray(theArray5, ARRAY_SIZE(theArray5), thePivot);
	//printArray(theArray5, ARRAY_SIZE(theArray5));
	//printArray(theArray5, ARRAY_SIZE(theArray5));

/*........................................................................................................*/

	printf("\nTest Quick sorting\n");
	//fillArray(theArray5, ARRAY_SIZE(theArray5), 100);
	//printArray(theArray5, ARRAY_SIZE(theArray5));
	clock_t theStart5 = clock();
	quickSort2(theArray5, 0, ARRAY_SIZE(theArray5) - 1);
	clock_t theEnd5 = clock();
	//printArray(theArray5, ARRAY_SIZE(theArray5));

/*........................................................................................................*/

    printf("\ntime of bubble sorting: %.10f\n", (double)(theEnd1 - theStart1) / CLOCKS_PER_SEC);
    printf("\ntime of selection sorting: %.10f\n", (double)(theEnd2 - theStart2) / CLOCKS_PER_SEC);
    printf("\ntime of insertion sorting: %.10f\n", (double)(theEnd3 - theStart3) / CLOCKS_PER_SEC);
	printf("\ntime of Shell sorting: %.20f\n\n", (double)(theEnd4 - theStart4) / CLOCKS_PER_SEC);
	printf("Finish the partition with a pivot: %d\n", partitionIt(theArray5, 0, ARRAY_SIZE(theArray5) - 1, 99));
	printf ("time of Quick sorting: %.20f\n", (double)(theEnd5 - theStart5)/CLOCKS_PER_SEC);
	//return 0;

	system("pause");
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
void fillArray(int anArray[], int aSize, int aPivot)
{
srand(0);
for (int i = 0; i < aSize; i++)
{
anArray[i] = rand() % (2 * aPivot);
}
}

//Bubble sort
void BubbleSort(int anArray[], int aSize)
{
	for (int theOut = aSize - 1; theOut > 1; theOut--)
	{
		for (int theIn = 0; theIn < theOut; theIn++)
		{
			if (anArray[theIn] > anArray[theIn + 1])
			{
				int theTmp = anArray[theIn];
				anArray[theIn] = anArray[theIn + 1];
				anArray[theIn + 1] = theTmp;
			}
		}
	}
}

//Insertion sort
void InsertionSort(int anArray[], int aSize)
{
	for (int theOut = 1; theOut < aSize; theOut++)
	{
		int theTmp = anArray[theOut];
		int theIn = theOut;

		while (theIn > 0 && anArray[theIn - 1] >= theTmp)
		{
			anArray[theIn] = anArray[theIn - 1];
			--theIn;
		}

		anArray[theIn] = theTmp;
	}
}


// quick sort
#if 0 //{
int partitionIt(int anArray[], int aLeftIndex, int aRightIndex, int aPivot)
{
	int theLeft = aLeftIndex - 1;
	int theRight = aRightIndex + 1;

	while (1)
	{
		// search the bigest element
		while (theLeft < aRightIndex && anArray[++theLeft] < aPivot);

		// search the lowest element
		while (theRight > aLeftIndex && anArray[--theRight] > aPivot);

		if (theLeft >= theRight) // pointer are the same 
		{
			break;
		}
		else
		{
			//lets to swap elements
			int theTmp = anArray[theLeft];
			anArray[theLeft] = anArray[theRight];
			anArray[theRight] = theTmp;
		}
	}

	return theLeft; // return break position
}
#else //}{

int partitionIt(int anArray[], int aLeftIndex, int aRightIndex, int aPivot)
{
	int theLeft = aLeftIndex - 1;
	int theRight = aRightIndex;

	while (1)
	{
		// search the bigest element
		while (anArray[++theLeft] < aPivot);

		// search the lowest element
		while (theRight > 0 && anArray[--theRight] > aPivot);

		if (theLeft >= theRight) // pointer are the same 
		{
			break;
		}
		else
		{
			//lets to swap elements
			int theTmp = anArray[theLeft];
			anArray[theLeft] = anArray[theRight];
			anArray[theRight] = theTmp;
		}
	}

	//lets to swap elements
	int theTmp = anArray[theLeft];
	anArray[theLeft] = anArray[aRightIndex];
	anArray[aRightIndex] = theTmp;

	return theLeft; // return break position
}
#endif

void quickSort(int anArray[], int aLeftIndex, int aRightIndex)
{
	if (aRightIndex - aLeftIndex <= 0)
	{
		return; // the array size equals to 1 - the array is fully sorted
	}

	int thePivot = anArray[aRightIndex];
	int thePartitionIndex = partitionIt(anArray, aLeftIndex, aRightIndex, thePivot);

	//left part sorting
	quickSort(anArray, aLeftIndex, thePartitionIndex - 1);

	//right part sorting
	quickSort(anArray, thePartitionIndex + 1, aRightIndex);
}

void swap(int anArray[], int aLeftIndex, int aRightIndex)
{
	int theTmp = anArray[aLeftIndex];
	anArray[aLeftIndex] = anArray[aRightIndex];
	anArray[aRightIndex] = theTmp;
}

int mediana(int anArray[], int aLeftIndex, int aRightIndex)
{
	int theCenter = (aLeftIndex + aRightIndex) / 2;

	if (anArray[aLeftIndex] > anArray[theCenter])
	{
		swap(anArray, aLeftIndex, theCenter);
	}

	if (anArray[aLeftIndex] > anArray[aRightIndex])
	{
		swap(anArray, aLeftIndex, aRightIndex);
	}

	if (anArray[theCenter] > anArray[aRightIndex])
	{
		swap(anArray, theCenter, aRightIndex);
	}

	swap(anArray, theCenter, aRightIndex - 1);

	return anArray[aRightIndex - 1];
}

int m_partitionIt(int anArray[], int aLeftIndex, int aRightIndex, int aPivot)
{
	int theLeft = aLeftIndex;
	int theRight = aRightIndex - 1;

	while (1)
	{
		// search the bigest element
		while (anArray[++theLeft] < aPivot);

		// search the lowest element
		while (anArray[--theRight] > aPivot);

		if (theLeft >= theRight) // pointer are the same 
		{
			break;
		}
		else
		{
			//lets to swap elements
			swap(anArray, theLeft, theRight);
		}
	}

	//lets to swap elements
	swap(anArray, theLeft, aRightIndex - 1);

	return theLeft; // return break position
}

void quickSort2(int anArray[], int aLeftIndex, int aRightIndex)
{
	int theSize = aRightIndex - aLeftIndex + 1;

	if (theSize <= 3)
	{
		m_manualSort(anArray, aLeftIndex, aRightIndex);
	}
	else
	{
		int thePivot = mediana(anArray, aLeftIndex, aRightIndex);
		int thePartitionIndex = m_partitionIt(anArray, aLeftIndex, aRightIndex, thePivot);

		//left part sorting
		quickSort(anArray, aLeftIndex, thePartitionIndex - 1);

		//right part sorting
		quickSort(anArray, thePartitionIndex + 1, aRightIndex);
	}
}

void m_manualSort(int anArray[], int aLeftIndex, int aRightIndex)
{
	int theSize = aRightIndex - aLeftIndex + 1;

	if (theSize <= 1)
	{
		return;
	}

	if (2 == theSize)
	{
		if (anArray[aLeftIndex] > anArray[aRightIndex])
		{
			swap(anArray, aLeftIndex, aRightIndex);
		}
		return;
	}
	else
	{
		// 3 elementes
		if (anArray[aLeftIndex] > anArray[aRightIndex - 1])
		{
			swap(anArray, aLeftIndex, aRightIndex - 1);
		}

		if (anArray[aLeftIndex] > anArray[aRightIndex])
		{
			swap(anArray, aLeftIndex, aRightIndex);
		}

		if (anArray[aRightIndex - 1] > anArray[aRightIndex])
		{
			swap(anArray, aRightIndex - 1, aRightIndex);
		}
	}
}

// selection sort
void SelectionSort(int anArray[], int aSize)
{
	for (int theOut = 0; theOut < aSize - 1; theOut++)
	{
		int theMinIndex = theOut;

		for (int theIn = theOut + 1; theIn < aSize; theIn++)
		{
			if (anArray[theIn] < anArray[theMinIndex])
			{
				theMinIndex = theIn;
			}
		}

		int theTmp = anArray[theOut];
		anArray[theOut] = anArray[theMinIndex];
		anArray[theMinIndex] = theTmp;
	}
}
// Shell sort
void ShellSort(int anArray[], int aCount)
{
	int theInner = 0;
	int theOuter = 0;
	int theH = 1; // start h = 1

				  //1. Calculate start value of h
	while (theH <= aCount / 3)
	{
		theH = theH * 3 + 1; // 1, 4, 13, 40, 121, ....
	}

	//2. Sequental decrease h to 1
	while (theH > 0)
	{
		for (theOuter = theH; theOuter < aCount; theOuter++)
		{
			int theTmp = anArray[theOuter];
			theInner = theOuter;

			// the first sub-array {0, 4, 8}
			while (theInner > theH - 1 && anArray[theInner - theH] >= theTmp)
			{
				anArray[theInner] = anArray[theInner - theH];
				theInner -= theH;
			}

			anArray[theInner] = theTmp;
		}

		theH = (theH - 1) / 3; //decrease h
	}
	system ("pause");
}

