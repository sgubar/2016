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
	int Param[C], Num, k = 0,rezult; 
	char Letter[A];
	printf("\nInput Num to hexadecimal converts (less than 1000): ");
	scanf("%d", &Num);
	if(Num>1000)
	printf("Incorrect input");
	else 
	{
	while(Num>16)
	{
	Param[k]= Num%16;
	switch(Param[k])
	{
		case 10 : Letter[k] = 'A'; break;
		case 11 : Letter[k] = 'B'; break;
		case 12 : Letter[k] = 'C'; break;
		case 13 : Letter[k] = 'D'; break;
		case 14 : Letter[k] = 'E'; break;
		case 15 : Letter[k] = 'F'; break;
	}
	Num = Num / 16; 
	k = k++;
	}
	Param[k] = Num; 
	switch(Param[k]) 
	{
		case 10 : Letter[k] = 'A'; break;
		case 11 : Letter[k] = 'B'; break;
		case 12 : Letter[k] = 'C'; break;
		case 13 : Letter[k] = 'D'; break;
		case 14 : Letter[k] = 'E'; break;
		case 15 : Letter[k] = 'F'; break;
	}
	printf ("Hexadecimal number is: ");
	for(rezult=k;rezult>-1;rezult--)
	{
	if (Param[rezult]>9) 
	printf("%c", Letter[rezult]);
	else 
	printf("%d", Param[rezult])	;
	}
	}
	getch();
}
