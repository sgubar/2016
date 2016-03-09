//
//  hex.c
//  dk-51
//
//  Created by Sergey Fedorenko on 3/6/16.
//  Copyright (C) 2016 Sergey Fedorenko. All rights reserved.
//
#include<stdio.h>
#include "hex.h"
const int C = 20; A=19;
void doHex()
{
	int Array[C], Num2, k = 0,m; 
	char Char[A];
	printf("\nInput Num2 to hexadecimal converts (less than 1000): ");
	scanf("%d", &Num2);
	if(Num2>1000)
	printf("Incorrect input");
	else 
	{
	while(Num2>16)
	{
	Array[k]= Num2%16;
	switch(Array[k])
	{
		case 10 : Char[k] = 'A'; break;
		case 11 : Char[k] = 'B'; break;
		case 12 : Char[k] = 'C'; break;
		case 13 : Char[k] = 'D'; break;
		case 14 : Char[k] = 'E'; break;
		case 15 : Char[k] = 'F'; break;
	}
	Num2 = Num2 / 16; 
	k = k++;
	}
	Array[k] = Num2; 
	switch(Array [k]) 
	{
		case 10 : Char[k] = 'A'; break;
		case 11 : Char[k] = 'B'; break;
		case 12 : Char[k] = 'C'; break;
		case 13 : Char[k] = 'D'; break;
		case 14 : Char[k] = 'E'; break;
		case 15 : Char[k] = 'F'; break;
	}
	printf ("Hexadecimal number is: ");
	for(m=k;m>-1;m--)
	{
	if (Array[m]>9) 
	printf("%c", Char[m]);
	else 
	printf("%d", Array[m])	;
	}
	}
	getch();
}
