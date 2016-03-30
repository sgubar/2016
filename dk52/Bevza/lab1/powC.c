//
//  main.c
//  Lab1
//
//
//  Created by Iryna Bevza.
//  Copyright (C) 2016 Iryna Bevza. All rights reserved.
//
#include <stdio.h>
#include "powC.h"
int PowC()
{
	int C=0, y=0;
	printf("Enter C\n");
	scanf("%i", &C);
	PowC=1;
	y=0;
	do {
	PowC=PowC*5;
	y++;
}
	while (y!=C);
	printf("PowC=%i\n", PowC);
	return 0;
}

