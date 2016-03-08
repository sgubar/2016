//
//
//  Laboratorna1
//
//  Created by Sorokin Dmytro on 07/03/16.
//  Copyright © 2016 Sorokin Dmytro. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Untitled1.h"

int main()
{
    float S,A,B,C,D,Q;
    printf ("Vipolnite deistvie \nQ=((A^2+B^2)/(B+5^C))+B!\n");//пояснюємо ціль
    printf ("Zadaite A,B,C\n");//запитоємо значення змінних
    scanf ("%f",&A);
    //printf ("A=%f\n",A);
    scanf ("%f",&B);
    //printf ("B=%f\n",B);
    scanf ("%f",&C);
    //printf ("C=%f\n",C);
    D=doFactorial(B);//рахуємо факторіал
    S=doPower(C);//рахуємо степінь
    //printf ("\nFactorial B= %f Power 5= %f\n",D,S);//перевіряемо значення
    if ((B+S)!=0)//перевірка на "дурня"
    {
            Q=(((A*A+B*B)/(B+S))+D);
            printf ("Otvet=%f",Q);
    }
        else
            printf ("Perezadaite znacheniya, znamenatel raven 0");

    return 0;
}
