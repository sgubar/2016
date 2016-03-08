/* Copyright (c) 2016 Aleksander Mahnyov. All rights reserved.*/

#include <stdio.h>
#include "calculate.h"
#include "biclycleMath.h"

void doFormula(int argA, int argB, int argC);

void doFormula(int argA, int argB, int argC){ //calculates the result, with bicyleMath formulas
    if(argB != 0){
        double finalResult = bicycleModulo(argA*argC-argB) * bicycleSum(argA) / bicyclePow(argB, 3); //main formula
        printf("Final result: %f\n", finalResult);
// debug lefrowers, let's just leave it here.
//        printf("Mod: %f\n", bicycleModulo(argA*argC-argB));
//        printf("Sum: %f\n", bicycleSum(argA));
//        printf("Pow: %f\n", bicyclePow(argB, 3));
    } else {
        printf("Invalid arguments!\n");
    }
}
