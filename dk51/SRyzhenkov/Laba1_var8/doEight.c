//
// Laba. 1 var. 8
//
//  Created by Ryzhenkov Serhii on 08/03/16.
//  Copyright © 2016 Ryzhenkov Serhii. All rights reserved.

 int doEight();
 int doEight()
 {
    int result;
    int iter = 0;
    int output[100];    //Создали и объявили массив для записи остачи от деления
    int i;
    printf("Enter the number: "); //запросили данные у пользователя
    scanf("%d", &result);
    //цикл для выполнения поставленной нам задачи
    while(result>=8){                   //Пока число, которое ввел пользователь, делится на 8, цикл выолняется
        output[iter] = result%8;        //запись остачи от деления в массив
        result /= 8;
        iter++;
    }
    output[iter] = result;              //записываем в массив последнее число, при котором мы вышли из цикла
    for(i = iter; i>=0; i--)            //цикл для записи данных массива в обратной последовательности
    {
        printf("%d", output[i]);
    }
 }
