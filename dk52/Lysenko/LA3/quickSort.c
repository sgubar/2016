#include "quickSort.h"

//Metod "bistroi" sortirovki
void quickSort(int *Array[], int j)
{
	int size = j;
	int i = 0;
	int c = Array[(int)(j/2)];
	int tmp = 0;
	do{
		while (Array[i] < c)i++;
		while (Array[j] > c)j--;
			
			if (i <= j)
		{
			tmp = Array[i];
			Array[i] = Array[j];
			Array[j] = tmp;
			i++;
			j--;
		}
	}

	while (i <= j);
	if (j>0) quickSort(Array, j);
	if (size > i) quickSort(Array+i, size-i);
}
