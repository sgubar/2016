#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fact.h"
#include"sumFact.h"


int main (){

    float result;
    int A, B, C;

    while(1){
        printf("Enter A\n");
        scanf("%d",&A);

        printf("Enter B\n");
        scanf("%d",&B);
        if (B == 0){
            printf("Please change the value B\n");
            continue;
        }

        printf("Enter C\n");
        scanf("%d",&C);
        break;
    }
    
    result = A * sqrt(B + C)/B + sumFact(C,A);

    printf("%lf\n",result);

    system("pause");
    return 0;
}



