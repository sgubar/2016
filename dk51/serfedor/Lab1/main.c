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
	doOctal();//Об'ява функції конвертації у вісімкову систему числень
	doHex();//Об'ява функції конвертації у шістнадцяткву систему числень
	printf ("\nThanks");
	getch();
}

