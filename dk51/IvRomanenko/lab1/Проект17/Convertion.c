
// 
//  Lab1
//
//  Created by Ivan Romanenko on 02/29/16.
//  Copyright © 2016 Ivan Romanenko. All rights reserved.
//
#include <stdio.h>
#include "Convertion.h"


int Convertion()
{
	int F = 0;
	char Numb[3];
	printf("Enter a numbern in HEX only 2 symbols\n");
	scanf_s("%s", Numb, sizeof Numb);
	for (int i = 0; i < 2; i++){
		switch (Numb[i]){
		case 'F':
			Numb[i] = 15;
			break;
		case 'A':
			Numb[i] = 10;
			break;
		case 'B':
			Numb[i] = 11;
			break;
		case 'C':
			Numb[i] = 12;
			break;
		case 'D':
			Numb[i] = 13;
			break;
		case 'E':
			Numb[i] = 14;
			break;
		}		
	}
	F = (Numb[0] * 16) + Numb[1];
	return (F);
	
}