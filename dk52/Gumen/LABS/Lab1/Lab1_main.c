// ******************************************************* //
//  Lab1_main.c 
//	Calculates Q=SUM A×(F-C), A from 1 to D, F is entered in hex
//  Created by Dima Humeniuk on 09/03/16. 
//  Copyright (C) 2016 Dima Humeniuk. All rights reserved. 

//1.Pre-processor Directives Section
#include <stdio.h>

//2.Global declarations section
void GetCDF();
int C,D,F,A=1,Q=0;
char hex[4];
int HexToDec (char ch[]);
int NumOfDigits(char num[]);
int CalculateQ (int C, int D, int F, int A, int Q);

//3.Subroutines Section
int main()
{
	printf("Hello! I calculate the sum of Q=A*(F-C) (A from 1 to D).\nYou enter whole decimal values of C and D and hexadecimal value of F (maximum 8 bits).\nLet's start!\n");
	GetCDF();
	Q=CalculateQ(C,D,F,A,Q);
	printf("Q=%d\n",Q);
	printf("Thanks for using our service! Come back soon!");
	return 0;	
}

void GetCDF()
{
	printf("Enter C:");
	scanf("%d",&C);
	printf("Enter D:");
	scanf("%d",&D);
	if (D <=0)
	{
	printf("Error: wrong D value.\n");
	return;
	}
	printf("Enter F (a hex number):");
	scanf("%s",hex);
	F=HexToDec(hex);
}

//Input:an hexadecimal number (8 bits max)
//Output: the number converted from hex to decimal
int HexToDec (char hnum[])
{
	int f=0,d1,d2,nd;
	nd=NumOfDigits(hex);
	if (nd==1||nd==2)
	{	
	if (nd==1)
	{
		switch(hnum[0])
		{
		case '0':f=0;break;
		case '1':f=1;break;
		case '2':f=2;break;
		case '3':f=3;break;
		case '4':f=4;break;
		case '5':f=5;break;
		case '6':f=6;break;
		case '7':f=7;break;
		case '8':f=8;break;
		case '9':f=9;break;
		case 'A':f=10;break;
		case 'B':f=11;break;
		case 'C':f=12;break;
		case 'D':f=13;break;
		case 'E':f=14;break;
		case 'F':f=15;break;
		default: printf("Error:hex number not recognised.F=0.\n");
			
		
		}
	}
	if (nd==2)
	{
		switch(hnum[0])
		{
		case '0':d1=0;break;
		case '1':d1=1;break;
		case '2':d1=2;break;
		case '3':d1=3;break;
		case '4':d1=4;break;
		case '5':d1=5;break;
		case '6':d1=6;break;
		case '7':d1=7;break;
		case '8':d1=8;break;
		case '9':d1=9;break;
		case 'A':d1=10;break;
		case 'B':d1=11;break;
		case 'C':d1=12;break;
		case 'D':d1=13;break;
		case 'E':d1=14;break;
		case 'F':d1=15;break;
		default: printf("Error:hex number not recognised. F=0.\n");	
				
		}
		switch(hnum[1])
		{
		case '0':d2=0;break;
		case '1':d2=16*1;break;
		case '2':d2=16*2;break;
		case '3':d2=16*3;break;
		case '4':d2=16*4;break;
		case '5':d2=16*5;break;
		case '6':d2=16*6;break;
		case '7':d2=16*7;break;
		case '8':d2=16*8;break;
		case '9':d2=16*9;break;
		case 'A':d2=16*10;break;
		case 'B':d2=16*11;break;
		case 'C':d2=16*12;break;
		case 'D':d2=16*13;break;
		case 'E':d2=16*14;break;
		case 'F':d2=16*15;break;
		default: printf("Error:hex number not recognised. F=0.\n");
				 
		}
		f=d1+d2;
	}
	}
	else
	printf("Error:hex number exceeds 8 bits. F=0.\n");
		
	return f;
}

//Input:a string of characters
//Output:number of elements in the string
int NumOfDigits(char num[])
{
	int i=0;
	while (num[i]!='\0')
	++i;
	return i;	
}

//Input: Values of C,D,F,A and Q (in decimal)
//Output: Value of Q
int CalculateQ (int C, int D, int F, int A, int Q)
{   
	for (;A<=D;A++)
	Q=Q+A*(F-C);
	return Q;
}



