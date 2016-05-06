
//  Main.c
//
//  Created by Dima Humeniuk on 5/6/16.
//  Copyright © 2016 Dima Humeniuk. All rights reserved.
//



#include "DynamicArray.h"
#include <stdio.h>

int main()
{

	int size = 0;
	int index = 0;
	int value = 0;
	int errorflag = 0;
	int memoryflag = 0;
	char i='0';

	printf("Enter the array size: ");//define the amount of memory to allocate 
	scanf_s("%d", &size);
	errorflag = SizeCheck(size);//check for invalid size
	if (errorflag > 0)
		return 0;
	createDAInt(size);

	while (i != '1')
	{
		
		printf("Enter the index: ");
		scanf_s("%d", &index);
		errorflag=IndexNegativeCheck(index);//check for vald index
		if (errorflag > 0)
			break;
		printf("Enter the value: ");
		scanf_s("%d", &value);
		memoryflag = IndexMemoryCheck(anArray, index);//check whether additional memory needed
		setValueAtIndex(anArray, value, index, memoryflag);
		printTheArray(anArray);
		printTheArrayInfo(anArray);
		printf("Enter an index to read the value: ");
		scanf_s("%d", &index);
		value = valueAtIndex(anArray, index);
		if (value == -1)
			return 0;
		printf("The value at index [%d] is: %d\n\n", index, value);
		printf("Press 1 to exit, any key to continue: ");
		scanf_s(" %c", &i);
	}
	
	freeDAInt(anArray);

	return 0;
}