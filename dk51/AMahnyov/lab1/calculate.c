/* Copyright (c) 2016 Aleksander Mahnyov. All rights reserved.*/

#include <stdio.h>
#include <stdlib.h>
#include "calculate.h"
#include "biclycleMath.h"

void doFormula(int argA, int argB, int argC);

void doFormula(int argA, int argB, int argC){ //calculates the result, with bicyleMath formulas
    if(argA == 0 || argC == 0){ //atoi returns 0, if you give it non-nubers
        printf("Your argument looks wrong. Continue? [y/n]: ");
        char answer;
        scanf(" %c", &answer); //scan for answer. For some reason, compiler says that I don't use return value of it
        if(answer == 'n' || answer == 'N'){ //if it is no, exit
            exit(0);
        }
    }
    if(argB != 0){
        double finalResult = bicycleModulo(argA*argC-argB) * bicycleSum(argA) / bicyclePow(argB, 3); //main formula
        printf("Final result: %f\n", finalResult);
    } else {
        printf("Invalid arguments!\n"); //if there is dividing by zero
    }
}
