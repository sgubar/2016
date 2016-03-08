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
	printf("Hello, this programm is converts decimal numbers to octal,\nand to hexadecimal numbers");
	doOctal();
	doHex();
	printf ("\nThanks");
	getch();
}

