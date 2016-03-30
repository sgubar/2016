//  doHexadecimal.c
//  Laba. 1 var. 8
//
//  Created by Ryzhenkov Serhii on 08/03/16.
//  Copyright © 2016 Ryzhenkov Serhii. All rights reserved.

#include "doHexadecimal.h"

int doHexadecimal()
{
    int result, iter = 0;
    int output[100];
    int i;
    char hex[16] = "0123456789ABCDEF"; //Создали и объявили массив, который будет использован для перевода остачи от деления в 16ричную систему

    printf("Enter the number: ");
    scanf("%d", &result);           // считывание аргумента

    while(result>=16){                  // цикл для перевода в 16ричну систему счисления
        output[iter] = result%16;
        result /= 16;
        iter++;
    }
    output[iter] = result;              //записываем в массив последнее число, при котором мы вышли из цикла

    for(i = iter; i>=0; i--){           //цикл для записи данных массива в обратной последовательности
        printf("%c", hex[output[i]]);   // вывод результата с учетом массива для 16ричной системы счисления
    }
}
