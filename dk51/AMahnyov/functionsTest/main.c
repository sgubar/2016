#include <stdio.h>
#include <stdlib.h>

int main()
{
    double result = 0;
    int i;
    for(i = 0; i < 4; i++){ //variable cycle
        result += bicyclePow(2, i); //sends it to makeshift pow
        printf("pow: %d\n", bicyclePow(2, i));
    }
    printf("Result: %f\n", result);
    return(0);
}

int bicyclePow(int num, int power){ //DIY pow, yay!
    if(power == 0){
        return(1);
    }
    int i;
    int result = num;
    for(i = 1; i < power; i++){
        result*=num;
    }
    return(result);
}
