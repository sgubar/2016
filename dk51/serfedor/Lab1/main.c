//
//  main.c
//  dk-51
//
//  Created by Sergey Fedorenko on 6/3/16.
//  Copyright (C) 2016 Sergey Fedorenko. All rights reserved.
//
#include<stdio.h>
#include "octal.h"
main()
{
	int Param;
	printf("Hello, this programm is converts decimal numbers to octal,\nand to hexadecimal numbers");
	printf ("\nSelect the number system (1-Octal; 2 - Hexadecimal): ");
	scanf("%d", &Param);
	switch(Param)
	{
	case 1 : doOctal();break;
	case 2 : doHex();break;
	}
	printf ("\nThanks");
	getch();
}

