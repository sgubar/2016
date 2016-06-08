#include "shellSort.h"

//Metod sortirovki "Shella"
void shellSort(int *Array[], int number_of_elements)
{
	int i, j, increment, temp;
	for (increment = number_of_elements / 2; increment > 0; increment /= 2)
	{
		for (i = increment; i<number_of_elements; i++)
		{
			temp = Array[i];
			for (j = i; j >= increment; j -= increment)
			{
				if (temp < Array[j - increment])
				{
					Array[j] = Array[j - increment];
				}
				else
				{
					break;
				}
			}
			Array[j] = temp;
		}
	}
}
