#include "SimpleSort.h"

void bubbleSort(int Array[], int N)		// The function of Bubble sorting
{
	int theOut;
	for (theOut = N - 1; theOut > 1; theOut --)
	{
		int theIn;
		for (theIn = 0; theIn < theOut; theIn ++)
		{
			if (Array[theIn] > Array[theIn + 1])
			{
				int theTmp = Array[theIn];
				Array[theIn] = Array[theIn + 1];
				Array[theIn + 1] = theTmp;
			}
		}
	}
}

void selectionSort(int Array[], int N)		// The function of Selection sorting
{
	int theOut;
	for (theOut = 0; theOut < N - 1; theOut ++)
	{
		int theMinIndex = theOut;
		int theIn;
		for (theIn = theOut + 1; theIn < N; theIn ++)
		{
			if (Array[theIn] < Array[theMinIndex])
			{
				theMinIndex = theIn;
			}
		}
	
		int theTmp = Array[theOut];
		Array[theOut] = Array[theMinIndex];
		Array[theMinIndex] = theTmp;
	}
}

void insertionSort(int Array[], int N)		// The function of Insertion sorting
{
	int theOut;
	for (theOut = 1; theOut < N; theOut ++)
	{
		int theTmp = Array[theOut];
		int theIn = theOut;
	
		while (theIn > 0 && Array[theIn - 1] >= theTmp)
		{
			Array[theIn] = Array[theIn - 1];
			-- theIn;
		}
	
		Array[theIn] = theTmp;
	}
}
