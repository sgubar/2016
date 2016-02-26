#include <stdio.h>
#include "calculate.h"
#include "biclycleMath.h"

static void checkAndDo(int A, int B, int C);

void doCalculation()
{
    int paramA, paramB, paramC;
    printf("Enter the parameters, space separated: ");
    scanf("%d %d %d", &paramA, &paramB, &paramC); //ask user for parameters
    checkAndDo(paramA, paramB, paramC);
}

void checkAndDo(int A, int B, int C){
    if(C == 0){ //to avoid dividing by zero
        printf("Invalid input!");
        }else{
            int finalResult = bicycleModulo(A*C-B) / bicyclePow(C, 3) * bicycleSum(A); //main formula

            printf("%d\n", bicycleModulo(A*C-B));
            printf("%d\n", bicyclePow(C, 3));
            printf("%d\n", bicycleSum(A));

            //printf("%d", finalResult);
        }
}
