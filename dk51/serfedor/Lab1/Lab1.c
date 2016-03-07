#include<stdio.h>
#include "octal.h"
const int N = 20;//Rozmir masiva
void doOctal()
{
	int Array[N], Num1, i = 0,d;
	printf("Input Num1: ");
	scanf("%d", &Num1);
	while(Num1>8)
	{
	
	Array[i]= Num1%8;
	Num1 = Num1 / 8;
	i = i++;
	}
	Array[i] = Num1;
	for(d=i;d>-1;d--)
	{
	printf ("%d", Array[d]);
	}
	getch();
}
