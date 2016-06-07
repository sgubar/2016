//
//  function.h
//  List Laba2
//
//  Created by Tsymbal Olexandr on 19/05/16.
//  Copyright © 2016 OlTsymbal. All rights reserved.
//
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int strlen(char *massiv);

int strlen(const char *massiv)
{
	int i;
	for (i = 0; *massiv != '\0'; massiv++)
	{
		i++;
	}
	return i;
}