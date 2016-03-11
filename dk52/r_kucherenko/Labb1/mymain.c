//
//  mymain.c
//  lab1
//
//  Created by Ruslan Kucherenko on 6/03/16.
//  Copyright (C) 2016 Ruslan Kucherenko. All rights reserved.
//
#include <stdio.h>
#include "ProgramofConversion.h"


int main()
{
	start:
	doProgramofConversion();
	printf("\nThank you for using this program\n");
	goto start;
	return 0;
}
