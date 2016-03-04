#include <stdio.h>
#include "calculate.h"
#include "biclycleMath.h"

void doFormula(int argA, int argB, int argC);

void doFormula(int argA, int argB, int argC){ //calculates the result, with bicyleMath formulas
    if(argB != 0){
        double finalResult = bicycleModulo(argA*argC-argB) / bicyclePow(argB, 3) * bicycleSum(argA); //main formula
        printf("Final result: %f\n", finalResult);
    } else {
        printf("Invalid arguments!\n");
    }
}
