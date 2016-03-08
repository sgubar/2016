//
//  octal.c
//  dk-51
//
//  Created by Sergey Fedorenko on 3/6/16.
//  Copyright (C) 2016 Sergey Fedorenko. All rights reserved.
//
#include<stdio.h>
#include "octal.h"
const int N = 20;
void doOctal() 
{
	int Array[N], Num1, i = 0,d;
	printf("\nInput Num1 to octal converts (less than 1000): ");
	scanf("%d", &Num1);
	if(Num1>1000)
	printf("Incorrect input");
	else{
	while(Num1>8)
	{
	
	Array[i]= Num1%8;
	Num1 = Num1 / 8;
	i = i++;
	}
	Array[i] = Num1;
	printf ("Octal number is: ");
	for(d=i;d>-1;d--)
	{
	printf ("%d", Array[d]);
	}
	}
	getch();
}
