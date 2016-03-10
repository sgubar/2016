#include <stdio.h>
#include <math.h>
#include "factorial.h"
#include "module.h"

void main(){
float B, Q;
int A;

printf("this program rozwiazue priklad Q<-(A!)/(A*2+B)");
printf("\n vvedite chislo A ");
scanf("%d", &A);
printf(" \n vvedite chislo B ");
scanf("%f", &B);
Q=factorial(A)/module(A*2+B);
if ((A*2+B)<=0)
printf("error\n");
else
printf("Q= %f\n", Q );
system("pause");
}