#include <stdio.h>
#include <math.h>
#include "factorial.h"
#include "module.h"

void main(){
float B, Q;
int A;

printf("this program rozwiazue priklad Q<-(A!)/(A*2+B)");
begin:
printf("\n vvedite chislo A ");
scanf("%d", &A);
printf(" \n vvedite chislo B ");
scanf("%f", &B);
if (A*2+B==0)
{
printf("2A+B=0,to try again type 1, to exit type 0 ");
scanf("%d", &A);
if(A==0) goto mark;
else goto begin;
}

Q=factorial(A)/module(A*2+B);
printf("Q= %f\n", Q );
system("pause");
mark:
printf("End\n");
}