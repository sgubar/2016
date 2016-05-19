#include "RewriteElement.h"

void RewriteElement(int *dynarray)
{
	int target_indx, target_value;

	printf("Write an index: ");
	scanf_s("%d", &target_indx);
	printf("Write a value: ");
	scanf_s("%d", &target_value);

	dynarray[target_indx - 1] = target_value;
}
