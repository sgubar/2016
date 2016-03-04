#include "biclycleMath.h"
#include <stdio.h>

double bicycleSum(int iterations);
double bicycleModulo(int input);
double bicyclePow(int num, int power);

//untested!
double bicycleSum(int iterations){ //sum of 2^parameter
    int result = 0;
    int i = 0;
    for(i = 0; i < iterations; i++){ //variable cycle
        result += bicyclePow(2, i); //sends it to makeshift pow
    }
    return(result);
}

//works!
    double bicycleModulo(int input){//inverts number, if negative
    if(input < 0){
        input*=(-1);
    }
    return(input);
    }

//works!
double bicyclePow(int num, int power){ //DIY pow, yay!
    int i = 0;
    int result = num - 1;
    for(i = 0; i < power; i++){
        result*=num;
    }
    return(result);
}
