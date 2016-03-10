// ******************************************************* //
//  Lab1_main.c 
//	Calculates Q=SUM A×(F-C), A from 1 to D, F is entered in hex
//  Created by Dima Humeniuk on 09/03/16. 
//  Copyright (C) 2016 Dima Humeniuk. All rights reserved. 

//1.Pre-processor Directives Section
#include <stdio.h>
#include "MyHexToDec.h"
#include "MySum.h"
//2.Global declarations section

//3.Subroutines Section
int main(void)
{
	int C,D,F;
	int A=1,Q=0,num_dig;
	char hex[4];
	printf("Hello! I calculate the sum of Q=A*(F-C) for 1<=A<=D.\nYou enter whole decimal values of C and D and hexadecimal value of F (maximum 8 bits).\nLet's start!\n");
	printf("Enter C:");
	scanf("%d",&C);
	printf("Enter D:");
	scanf("%d",&D);
	if (D<=0){
	printf("Error: wrong D value.");
	return 0;}
	printf("Enter F (a hex number):");
	scanf("%s",hex);
	num_dig=NumOfDigits(hex);
	F=MyDecimal(num_dig, hex);
	Q=MySum(C,D,F,A,Q);
	printf("Q=%d\n",Q);
	printf("It was nice to meet you! Come back soon!");
	return 0;	
}
