//
//  main.c
//  lab1
//
//  Created by Nazar Koshariuk on 3/10/16.
//  Copyright (C) 2016 Nazar Koshariuk. All rights reserved.
//

#include <stdio.h>
#include "Fakt.h"
#include "Fraction.h"
float Frac, Q;
int Fakto,ParamA, ParamB, ParamC, ParamD=0;
int main(int argc, const char * argv[])
{
	printf("Please enter A, B, C\n");
	scanf("%d%d%d", &ParamA, &ParamB, &ParamC); //read paramA, ParamB, ParaC;
	if (ParamB + (ParamC * ParamC ) == 0){
		printf("The denominator is 0, please try again");
	 }
	else{
		doFakt(ParamB, ParamD);//Calculatoin factorial
		doFraction(ParamA, ParamB, ParamC);// Calculation fractions
		Q = Frac + Fakto;
		printf("Result %.3f\n", Q);
		printf("Thanks!\n");
	 }
   //return 0;
   system("PAUSE");
}
