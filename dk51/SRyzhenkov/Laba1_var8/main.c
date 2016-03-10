//  main.c
//  Laba. 1 var. 8
//
//  Created by Ryzhenkov Serhii on 08/03/16.
//  Copyright © 2016 Ryzhenkov Serhii. All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include "doEight.h"
#include "doHexadecimal.h"

int main()
{
    int variation;
    printf("Добро пожаловать в программу для конвертации чисел.\n"
           "Вам доступно несколько систем счисления на выбор.\n"
           "Просьба, для корректных расчетов, не вводить числа с плавающей запятой.\n");
    printf("1 - Converter of the decimal system in octal notation\n");
    printf("2 - Converter of the decimal system in hexadecimal notation\n");
    scanf("%i", &variation);
    switch(variation){
    case(1):
        doEight();
    break;
    case(2):
        doHexadecimal();
    break;
    }
}

