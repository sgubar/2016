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
	int Array[N], Num, i = 0,rezult;
	printf("\nInput Num to octal converts (less than 1000): ");
	scanf("%d", &Num);
	if(Num>1000)
	printf("Incorrect input");
	else{
	while(Num>8)
	{
	
	Array[i]= Num%8;
	Num = Num / 8;
	i = i++;
	}
	Array[i] = Num;
	printf ("Octal number is: ");
	for(rezult=i;rezult>-1;rezult--)
	{
	printf ("%d", Array[rezult]);
	}
	}
	getch();
}
