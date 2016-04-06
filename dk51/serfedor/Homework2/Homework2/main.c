//
//  main.c
//  Homework2
//
//  Created Sergey Fedorenko on 4/6/16.
//  Copyright © 2016 Sergey Fedorenko. All rights reserved.
//
#include "DynamicArray.h"
#include <stdio.h>
int main(int argc, const char * argv[])
{
	printf("Create Dynamic Array with integer value\n");

	DynamicIntArray *anArray = createDAInt(10);
	printf("Delete\n");
	freeDAInt(anArray);
	
	printf("Done\n");		
	
	system("pause");
}