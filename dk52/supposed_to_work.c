/////////////////////////////////////////////////////////
//main.c                                               //
//Labwork_1                                           //
//Created by Vadim Solodun                             //
//Copyright (C) 2016 Solodun Vadim. All rights reserved//
/////////////////////////////////////////////////////////


#include <math.h>
#include <stdio.h>
 void main()
{
float A, B, C, F, N, G;
int D;
    printf("enter A\n");
	scanf("%f", &A);
	printf("enter B\n");
	scanf("%f", &B);
	printf("enter C\n");
	scanf("%f", &C);	
	printf("enter D\n");
	scanf("%d", &D);
	F=(100-B-C);
	N=(A+B+C)/F;
	if (F=0) 
	{
	}
	for (D=0;D<=A;D++)
	{ 
    G=N+pow(2,D+A);
    }
    printf("G= %f \n",G);
    system("pause");
    
}
