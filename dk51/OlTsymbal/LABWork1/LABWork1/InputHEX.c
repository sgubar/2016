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
		printf("Please Check your entries\n");
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
		printf("%d\n", number);
	}
	return(number);
}