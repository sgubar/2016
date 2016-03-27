#include <stdio.h>
#include <conio.h>
#include <stdlib.h> //exit
#include <locale.h>
#include "hex_converter.h"
#include "start.h"
#include "error_log.h"
#include "countsigma.h"

void error_log(int);
char a[20]; //массив "ответственный" за число F				
int length = 1, F_dec = 0, sigma = 0 , C, D; //Length - длина числа F, F_dec - его десятичное значение, sigma - сумма натуральных чисел от 1 до D, C - десятичная переменная

void main() {
	start(); //Ввод данных и проверка чисоа D
	elements();//Перевод числа F из шестнадцатеричной в десятичную систему + проверка правильности ввода числа F
	countsigma();// Подсчет суммы натуральных чисел от 1 до D
	printf("\nAnswer : %d\n", (F_dec - C)*sigma);//Подсчет и вывод окончательного ответа
};
