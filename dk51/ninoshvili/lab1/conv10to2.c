//conv10to2.c
//
//conversion from 10 to 2 and from 16 to 8
//
//made by Ninoshvili 05.05.16
//Copyright © 2016 Ninoshvili. All rights reserved.
//

#include<stdio.h>

int conv10to2(input)
{
	int index = 0;
	int chislo[20];

	//choose the number of binary by findind delivery
	do
	{
		if ((input % 2) == 1) 
			chislo[index] = 1;
		
		if ((input % 2) == 0)
			chislo[index] = 0;

		if (input == 1)
			chislo[index] = 1;

		input = (input - (input % 2)) / 2;
		index++;

	} while (input >= 1);

	index = index - 1;

	printf("your number in binary is:\n");

	//starting from the end output 
	for (index; index >= 0; index--)
		printf("%d", chislo[index]);

	printf("\n");
}