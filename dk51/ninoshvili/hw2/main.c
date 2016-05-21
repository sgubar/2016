#include <stdio.h>
#include <stdlib.h>
#include "DynamicArray.h"

int main()
{
	int size = 10;
	int index = 0;
	DynamicIntArray *array = createDAInt(size);

	setValueAtIndex(array, 24, 1);
	
	int value = valueAtIndex(array, 1);

	printf("%d\n", value);

	setValueAtIndex(array, 30, 15);

	value = valueAtIndex(array, 15);

	printf("%d\n", value);

	system("pause");
}