
// 
//  Lab1
//
//  Created by Ivan Romanenko on 02/29/16.
//  Copyright © 2016 Ivan Romanenko. All rights reserved.
//
#include <stdio.h>
#include "Vidnim.h"
int Vidnim(int F)
{
	int C;
	printf("Enter a value of C\n");
	scanf_s("%d", &C);
	int vidpovid = F - C;
	return(vidpovid);
}