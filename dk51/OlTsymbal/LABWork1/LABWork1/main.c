#include <stdio.h>
#include <stdlib.h>

//
//  InputHEX.h
//  Lab1
//
//  Created by Olexander Tsymbal on 02/28/16.
//  Copyright © 2016 Olexander Tsymbal. All rights reserved.
//
#include"InputHEX.h"
#include"Input.h"
#include"Math.h"


int main()
{
	printf("It`s CALCULATION (SUM(from A=1 to D)Ax(F-B)) (F entered in hex)\n");// do this formula
	printf("Enter a number B\n");
	int numberB = doInput();//function doInput
	printf("Enter a number D\n");
	int numberD = doInput();
	int numberHEX = doInputHEX();
	
	int resultSub = Sub(numberHEX, numberB);//function of Sublimation
	SumandMult(resultSub, numberD);// functions of Sum and Multiplication
	system("pause");
}
