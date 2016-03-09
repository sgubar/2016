//
//  InputHEX.h
//  Lab1
//
//  Created by Olexander Tsymbal on 02/28/16.
//  Copyright © 2016 Olexander Tsymbal. All rights reserved.
//
#include<stdio.h>

#include"Math.h"

int Sub(int numberHEX, int numberB);
int Sum(int resultSub, int numberD);

int Sub(int numberHEX, int numberB) //it is function of Sublimation (F-B)
{
	if (numberHEX != 0)//if numberHEX not equal 0(there is no more two symbols or it is not 0)
	{
		int resultSub = numberHEX - numberB;
		/*printf("Sub=%d\n", resultSub);*/
		return(resultSub);
	}
	else
	{
		printf("Invalid arguments. Check you entries\n");//if there is more than two symbols of HEXnumber
		return 0;
	}
}


int SumandMult(int resultSub, int numberD)//it is function of SUM(Sum(from A=1 to D Multiplication)
{
	int resultMult, result = 0;
	for (int A=1 ; A <= numberD; A++)
	{
		resultMult = resultSub*A;//Multiplication(Ax(F-B))
		result += resultMult;//Sum(from A=1 to D Multiplication)
	}
	printf("RESULT=  %d\n", result);//output results
	return(result);
}