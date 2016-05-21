#include "DynamicArray.h"
#include <stdio.h>

int main()
{

	int size = 0;
	int index = 0;
	int value = 0;
	int error = 0;
	int memory = 0;
	char i = '0';

	printf("Enter the array size: ");//”знать какой обьем пам€ти нужно выделить
	scanf_s("%d", &size);
	error = SizeCheck(size);//проверка на правильность размера
	if (error > 0)
		return 0;
	createDAInt(size);

	while (i != '1')
	{

		printf("Enter the index: ");
		scanf_s("%d", &index);
		printf("You entered " "%d", index);
		error = IndexNegativeCheck(index); //проверка на действительный index
		if (error > 0)
			break;
		printf("\nEnter the value: ");
		scanf_s("%d", &value);
		printf("\nYou entered " "%d", value);
		memory = IndexMemoryCheck(anArray, index); //ѕроверка сколько нужно будет пам€ти
		setValueAtIndex(anArray, value, index, memory);
		printTheArray(anArray);
		printTheArrayInfo(anArray);
		printf("\nEnter an index to read the value: ");
		scanf_s("%d", &index);
		value = valueAtIndex(anArray, index);
		if (value == -1)
			return 0;
		printf("\nThe value at index [%d] is: %d\n\n", index, value);
	}

	freeDAInt(anArray);

	return 0;
}