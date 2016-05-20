//
//  main.c
//  Dz 2
//
//  Created by Nazar Bronnikiv on 4/7/16.
//  Copyright © 2016 Nazar Bronnikiv. All rights reserved.
//

#include <stdio.h>

#include "DynamicArray.h"


void printDAsize(DynamicIntArray *anArray);
void testArray();

int main()
{
	testArray();
	system("pause");
}

void testArray()
{
	printf("Create dynamic massive \n");
	
	DynamicIntArray *anArray = createDAInt(10);
	printDAsize(anArray);

	printf("\n Add number 5 at index 2 \n");
	setValueAtIndex(anArray, 5, 2);
	printf("Index[2] = %d \n", valueAtIndex(anArray, 2));
	printDAsize(anArray);

	printf("\n Add number 2 at index 0 \n");
	setValueAtIndex(anArray, 2, 0);
	printf("Index[0] = %d \n", valueAtIndex(anArray, 0));
	printDAsize(anArray);

	printf("\n Add number 140 at index 1 \n");
	setValueAtIndex(anArray, 140, 1);
	printf("Index[1] = %d \n", valueAtIndex(anArray, 1));
	printDAsize(anArray);

	printf("\n Add number 20 at index 20 \n");
	setValueAtIndex(anArray, 20, 20);
	printf("Index[20] = %d \n", valueAtIndex(anArray, 20));
	printDAsize(anArray);
	
	printf("\n Add number 25 at index 25 \n");
	setValueAtIndex(anArray, 25, 25);
	printf("Index[25] = %d \n", valueAtIndex(anArray, 25));
	printDAsize(anArray);
	
	freeDAInt(anArray);

}

void printDAsize(DynamicIntArray *anArray)
{
	printf("Physical size = %d \n Logical size = %d \n \n", anArray->physicalSize, anArray->logicalSize);
}
