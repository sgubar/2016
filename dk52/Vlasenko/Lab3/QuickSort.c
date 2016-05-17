#include "QuickSort.h"

void QuickSort(int Array[], int left, int right)	// The function of Quick sorting
{
      int i = left, j = right;
      int tmp;
      int pivot = Array[(left + right) / 2];
 
      while (i <= j)
	  {
            while (Array[i] < pivot)
                  i++;
            while (Array[j] > pivot)
                  j--;
            if (i <= j)
			{
                  tmp = Array[i];
                  Array[i] = Array[j];
                  Array[j] = tmp;
                  i++;
                  j--;
            }
      };
 
      if (left < j)
            QuickSort(Array, left, j);
      if (i < right)
            QuickSort(Array, i, right);
}
