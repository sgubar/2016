//
//  InputHEX.h
//  Lab1
//
//  Created by Olexander Tsymbal on 02/28/16.
//  Copyright © 2016 Olexander Tsymbal. All rights reserved.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "InputHEX.h"


int doInputHEX()
{
	int number = 0;
	char HEXnumber[4];
	printf("Enter HEXnumber (no more than two symbols)\n");
	scanf("%s", &HEXnumber);
	if (HEXnumber[2] != 0)
	{
		printf("Your argument is WRONG\n");
		printf("Please Check your entries\n");
		printf("Will you continue?(Y-Yes/N-No)\n");
		char answer;
		scanf(" %c", &answer); //scan for answer
		if (answer == 'n' || answer == 'N') //if it is no, exit
		{
			exit(0);
		}
		else//if it is yes return 0 to number
			return 0;
	}
	else
	{
		for (int i = 0; i < 2; i++)
		{
			switch (HEXnumber[i])
			{
			case 'f':
				HEXnumber[i] = 15;
				break;
			case 'e':
				HEXnumber[i] = 14;
				break;
			case 'd':
				HEXnumber[i] = 13;
				break;
			case 'c':
				HEXnumber[i] = 12;
				break;
			case 'b':
				HEXnumber[i] = 11;
				break;
			case 'a':
				HEXnumber[i] = 10;
				break;
			default:
				HEXnumber[i] -= 48;
				break;
			}
		}
		number = (HEXnumber[0] * 16) + HEXnumber[1];
		/*printf("%d\n", number);*/
	}
	return(number);
}