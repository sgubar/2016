/* Copyright (c) 2016 Aleksander Mahnyov. All rights reserved.*/

#include "biclycleMath.h"

double bicycleSum(int iterations);
double bicycleModulo(int input);
double bicyclePow(int num, int power);

//untested!
double bicycleSum(int iterations){ //sum of 2^parameter
    int result = 0;
    int i;
    iterations++; //because it begins with 0, and with, for example, B=3, you need to do the sum 4 times
    for(i = 0; i < iterations; i++){ //variable cycle
        result += bicyclePow(2, i); //sends it to makeshift pow
    }
    return(result);
}

//works!
    double bicycleModulo(int input){//inverts number, if negative
    if(input < 0){
        input*=(-1); //invert
    }
    return(input);
    }

//works!
double bicyclePow(int num, int power){ //DIY pow, yay!
    if(power == 0){
        return(1); //It is a mathematical rule, I don't know why it is 0
    }
    int i;
    int result = num;
    for(i = 1; i < power; i++){ //multiply result by itself %power% times
        result*=num;
    }
    return(result);
}
