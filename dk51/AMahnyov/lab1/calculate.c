#include <stdio.h>
#include "calculate.h"

static void checkAndDo(int A, int B, int C, int D);
static int bicycleSum(int param, int iterations);
static int bicycleModulo(int input);

void calculate()
{
    int paramA, paramB, paramC, paramD;
    printf("Enter the parameters, space separated: ");
    scanf("%d %d %d %d", &paramA, &paramB, &paramC, &paramD);
    checkAndDo(paramA, paramB, paramC, paramD);
}

void checkAndDo(int A, int B, int C, int D){
    if(C == 0){ //to avoid dividing by zero
        printf("Invalid input!");
        }else{
            int finalResult = bicycleModulo(A*C-B) / bicyclePow(C, 3) * bicycleSum(D, A); //main formula
            printf("%d", finalResult);
        }
}

int bicycleSum(int param, int iterations){ //sum of 2^parameter
    int result = 0;
    int i = 0;
    for(i = 0; i < iterations; i++){
        result += 2^param;
    }
    return(result);
}

int bicycleModulo(int input){ //inverts number, if negative
    if(input < 0) input*=(-1);
    return(input);
    }

int bicyclePow(int num, int power){ //DIY pow, yay!
    int i = 0;
    int result = 0;
    for(i = 0; i < power; i++){
        result*=num;
    }
    return(result);
    num = 0;
}
