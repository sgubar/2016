//
//  ProgramofConversion.c
//  lab1
//
//  Created by Ruslan Kucherenko on 6/03/16.
//  Copyright (C) 2016 Ruslan Kucherenko. All rights reserved.
//
#include <stdio.h>
#include "ProgramofConversion.h"

static void doConv10to16();
static void doConv16to10();
static void doConv10to8();
static void doConv8to10();

void doProgramofConversion()
{
	int act;
		printf("Select action\n");
		printf("1 - A10-A16\n");
		printf("2 - A16-A10\n");
		printf("3 - A10-A8\n");
		printf("4 - A8-A10\n");
		scanf_s("%i", &act);
		switch (act)
		{
		case 1:
		{
			doConv10to16();
			break;
		}
		case 2:
		{
			doConv16to10();
			break;
		}
		case 3:
		{
			doConv10to8();
			break;
		}
		case 4:
		{
			doConv8to10();
			break;
		}
		}
		
		return 0;
}
// A10->A16
void doConv10to16()
	{
	int num[20],i,k,f;
		printf("Enter the number:\n");
		scanf_s("%d", &f);
		num[1]=f/16;
		num[2]=f%16;
		for(k=2;k<=16;k+=2)
		{
		num[k+1]=num[k-1]/16;
		num[k+2]=num[k-1]%16;
		}
		printf("Answer:\n");
		for(i=16;i>=2;i-=2)
		{
		switch(num[i])
		{
		case 0:printf("0");continue;
		case 1:printf("1");continue;
		case 2:printf("2");continue;
		case 3:printf("3");continue;
		case 4:printf("4");continue;
		case 5:printf("5");continue;
		case 6:printf("6");continue;
		case 7:printf("7");continue;
		case 8:printf("8");continue;
		case 9:printf("9");continue;
		case 10:printf("A");continue;
		case 11:printf("B");continue;
		case 12:printf("C");continue;
		case 13:printf("D");continue;
		case 14:printf("E");continue;
		case 15:printf("F");continue;
		}
		}

		return 0;
}
// A16->A10
 void doConv16to10()
 {
	int i=0;
	int sum = 0;
	char hex_val[20];
	printf("Enter the number:\n");
	/*
	for(i;i<15;i++)
	{
		hex_val[i+1] = getchar();
		
		if(hex_val[i]=='\n')
			break;
	}
	*/
		gets(hex_val);
		for(i =0;i<strlen(hex_val);i++)
		{
		if(hex_val[i]<='9' && hex_val[i]>='0')
			sum = sum*16+hex_val[i]-'0';
		else if(hex_val[i]>='A' && hex_val[i]<='F')
			sum = sum*16+hex_val[i]-'A'+10;
		}
	
		printf("Answer:\n", sum);
	return 0;
} 
 // A10->A8
 void doConv10to8()
	{
	int num[20],i,k,f;
		printf("Enter the number:");
		scanf("%d", &f);
		num[1]=f/8;
		num[2]=f%8;
		for(k=2;k<=8;k+=2)
		{
		num[k+1]=num[k-1]/8;
		num[k+2]=num[k-1]%8;
		}
		printf("Answer:\n");
		for(i=8;i>=2;i-=2)
		{
		switch(num[i])
		{
		case 0:printf("0");continue;
		case 1:printf("1");continue;
		case 2:printf("2");continue;
		case 3:printf("3");continue;
		case 4:printf("4");continue;
		case 5:printf("5");continue;
		case 6:printf("6");continue;
		case 7:printf("7");continue;
		case 8:printf("8");continue;
		}
		}

		return 0;
}
 //A8->A10
  void doConv8to10()
 {
	int i;
	int val;
	int sum = 0;
	char oct_val[20];
	printf("Enter the number:\n");
	gets(oct_val);

	//val = oct_to_dec(oct_val);
	for(i =0;i<strlen(oct_val);i++)
	{
		sum = sum*8+oct_val[i]-'0';
	}
	printf("Answer:\n",sum);
	return 0;
}
