
// 
//  Lab1
//
//  Created by Ivan Romanenko on 02/29/16.
//  Copyright © 2016 Ivan Romanenko. All rights reserved.
//
#include <stdio.h>
#include "Summa.h"
int Summa(int vidp){
	int A = 0;
	int D;
	int result=0;
	int otvet=0;
	printf("Enter a value of D\n");
	scanf_s("%d", &D);
	for (; A <= D; A++)
	{
		otvet = A*vidp;
		result += otvet;
	}
	return(result);
}