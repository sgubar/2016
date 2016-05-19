//conv16to8.c
//
//conversion from 10 to 2 and from 16 to 8
//
//made by Ninoshvili 05.05.16
//Copyright © 2016 Ninoshvili. All rights reserved.
//

#include<stdio.h>
#include"conv16to8.h"

int conv16to8(decimal)
{
	int index = 0;
	int chislo[20];

	//choose the number of binary by findind delivery
	do
	{
		chislo[index] = (decimal % 8);

		decimal = (decimal - (decimal % 8)) / 8;
		index++;

	} while (decimal > 0);

	index = index - 1;

	printf("your number in octal is:\n");

	//starting from the end output 
	for (index; index >= 0; index--)
		printf("%d", chislo[index]);

	printf("\n");
}