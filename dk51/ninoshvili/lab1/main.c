//main.c
//
//conversion from 10 to 2 and from 16 to 8
//
//made by Ninoshvili 05.05.16
//Copyright © 2016 Ninoshvili. All rights reserved.
//

#define _CRT_SECURE_NO_WARNINGS //for using scanf, not scanf_s
#include<stdio.h>
#include"conv10to2.h"
#include"podgotovka.h"
#include"conv16to8.h"
#include"pow.h"
#include"proverka10.h"


int main()
{
	printf("hello, you can use me for conversion from one code of numbers to antother,\n");

	int vubor;
	int celoe;
	int conversion;
	int decimal;

	do
	{
		printf("for conversion form decimal to binary - press 1\n");
		printf("for conversion from hexadecimal to octal - press 2\n");
		scanf("%d", &vubor);
		char bug = getchar(); // debug scanf
	} while (vubor != 1 && vubor != 2);

	//choose the way to make conversion
	if (vubor == 1)
		{
			printf("you choose conversion from decimal to binary\n");
			
			//watching for the correct input data
			do
			{
				printf("please input postive, but not bigger than one million, integer decimal number\n");

				decimal = proverka10();

			} while ( decimal == -1 );

			conversion = conv10to2(decimal);
		}

	if (vubor == 2)
		{
			//watching for the correct input data and make first conversion, to decimal
			printf("you choose conversion from hexadecimal to octal\n");
			do
			{
				printf("please input postive, but not bigger than one million, integer hexidecimal number\n");

				decimal = podgotovka();
			} while (decimal == -1);

			conversion = conv16to8(decimal);
		}
	system("pause");
}