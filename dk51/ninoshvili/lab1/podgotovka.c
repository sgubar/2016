//podgotovka.c
//
//conversion from 10 to 2 and from 16 to 8
//
//made by Ninoshvili 05.05.16
//Copyright © 2016 Ninoshvili. All rights reserved.
//

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"podgotovka.h"
#include"pow.h"

int podgotovka()
{	
	int chislo[16];
	int index;
	int decimal = 0;

	//entry the number
	for (index = 0; index < 16; index++)
	{
		chislo[index] = getchar();
		if (chislo[index] == '\n')
			break;
	}

	//printing the number
	/*for (index = 0; index < 16; index++)
	{
		printf("%c", chislo[index]);
		if (chislo[index] == '\n')
			break;
	}*/
	printf("\nloading...\n");

	//search for mistake entry
	for (index = 0; index < 16; index++)
	{
		if (chislo[index] == '\n')
			break;
		if (chislo[index] == '0' || chislo[index] == '1' || chislo[index] == '2' || chislo[index] == '3' || chislo[index] == '4' || chislo[index] == '5' || chislo[index] == '6' || chislo[index] == '7' || chislo[index] == '8' || chislo[index] == '9' || chislo[index] == 'A' || chislo[index] == 'B' || chislo[index] == 'C' || chislo[index] == 'D' || chislo[index] == 'E' || chislo[index] == 'F')
		{
			printf(".\n");
		}
		else if (chislo[index])
		{
			printf("try again and use numbers, or\n A for 10,\n B for 11,\n C for 12,\n D for 13,\n E for 14,\n F for 15\n");
			return -1;
			break;
		}
	}
	int limit = index; //make limit for end of the loop

	//get from char to int
	for (index = 0; index < limit; index++)
	{
		if (chislo[index] == '\n')
			break;

		if (chislo[index] == '0' || chislo[index] == '1' || chislo[index] == '2' || chislo[index] == '3' || chislo[index] == '4' || chislo[index] == '5' || chislo[index] == '6' || chislo[index] == '7' || chislo[index] == '8' || chislo[index] == '9')
			chislo[index] = chislo[index] - 48;

		if (chislo[index] == 'A')
			chislo[index] = 10;

		if (chislo[index] == 'B')
			chislo[index] = 11;

		if (chislo[index] == 'C')
			chislo[index] = 12;

		if (chislo[index] == 'D')
			chislo[index] = 13;

		if (chislo[index] == 'E')
			chislo[index] = 14;

		if (chislo[index] == 'F')
			chislo[index] = 15;
	}

	//for (index = 0; index < limit; index++)
		//printf("%d\n", chislo[index]);

	int graniza = limit - 1;//make variable for power

	//from hexadecimal to decimal
	for (index = 0; index < limit; index++)
	{
		decimal = decimal + chislo[index] * pow(16, graniza);
		graniza--;
		//printf("decimal: %d\n", decimal);
	}
	
	if (decimal <= 1000000)
		return decimal;

	else if (decimal > 1000000)
	{
		int bug[100]; //for the rest from getchar
		for (index = 0; bug[index-1] == '\n'; index++)
			bug[index] = getchar();

		return -1;
	}
}