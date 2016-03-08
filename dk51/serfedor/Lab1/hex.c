//
//  hex.c
//  dk-51
//
//  Created by Sergey Fedorenko on 3/6/16.
//  Copyright (C) 2016 Sergey Fedorenko. All rights reserved.
//
#include<stdio.h>
#include "hex.h"
const int C = 20; A=19;//Встановлення кількості комірок для масивів
void doHex()// розкриття змісту функції
{
	int Array[C], Num2, k = 0,m;  //ініціалізація цілочисленних масиву та змінних 
	char Char[A];// ініціалізація символьного масиву 
	printf("\nInput Num2 to hexadecimal converts (less than 1000): ");
	scanf("%d", &Num2);// зберігання змінної
	if(Num2>1000)// умова, якщо введене число більше за 1000
	printf("Incorrect input");// вивід помилки
	else //якщо не виконуеться умова
	{
	while(Num2>16) //цикл ділення введеного числа на 16, поки останнє число >16
	{
	Array[k]= Num2%16; //присвоєння масиву остачі від ділення
	switch(Array[k])// цикл - інструкція, якщо значення остачі від ділення  дорівнює  ...
	{
		case 10 : Char[k] = 'A'; break;
		case 11 : Char[k] = 'B'; break;
		case 12 : Char[k] = 'C'; break;
		case 13 : Char[k] = 'D'; break;
		case 14 : Char[k] = 'E'; break;
		case 15 : Char[k] = 'F'; break;
	}
	Num2 = Num2 / 16; // ділення числа на 16
	k = k++; //перехід до наступної комірки масиву
	}
	Array[k] = Num2; // присвоєння останнього числа поділеного на 16 масиву
	switch(Array [k]) // цикл - інструкція, якщо значення  ділення  дорівнює  ...
	{
		case 10 : Char[k] = 'A'; break;
		case 11 : Char[k] = 'B'; break;
		case 12 : Char[k] = 'C'; break;
		case 13 : Char[k] = 'D'; break;
		case 14 : Char[k] = 'E'; break;
		case 15 : Char[k] = 'F'; break;
	}
	printf ("Hexadecimal number is: ");
	for(m=k;m>-1;m--)//заповнення комірок  задом на перед
	{
	if (Array[m]>9) // умова якщо значення масиву більше за 9
	printf("%c", Char[m]);
	else 
	printf("%d", Array[m])	;
	}
	}
	getch();
}
