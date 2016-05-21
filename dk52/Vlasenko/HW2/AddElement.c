#include "AddElement.h"

int AddElement(int *dynarray, int indx_f, int N_f)
{
	int target_indx, target_value;

	printf("Write an index: ");
	scanf_s("%d", &target_indx);
	printf("Write a value: ");
	scanf_s("%d", &target_value);

	N_f++;

	int *dynarraybigger = (int*)realloc(dynarray, N_f * sizeof(int)); // Expansion allocated memory for array with (N+1) number of integer values.

	for (indx_f = N_f; indx_f >= target_indx; indx_f--)
		dynarraybigger[indx_f] = dynarraybigger[indx_f - 1];
	dynarraybigger[target_indx - 1] = target_value;

	return dynarraybigger;
}
