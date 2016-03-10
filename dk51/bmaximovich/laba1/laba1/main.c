//  main.c 
//  laba1
// 
//  Created by Bogdan Maximovich on 8/03/16. 
//  Copyright (C) 2016 Bogdan Maximovich. All rights reserved. 

#include "Header.h"


int main(int argc, char *argv[])
{
	int a, b, c;
	printf("Enter A\n"); // displays a message "Enter A"
	scanf_s("%d", &a); // read the data entered from the keyboard and pointing to variable "A"
	printf("Enter B\n");
	scanf_s("%d", &b);
	printf("Enter C\n");
	scanf_s("%d", &c);
	if ((b + c*c) != 0) //checking for 0 in the denominator
	{
		double q = f(a, b, c); //type of floating point numbers
		printf("Result: %f\n", q);
	}
	else
		printf("Invalid arguments!\n");
	system("pause");
}