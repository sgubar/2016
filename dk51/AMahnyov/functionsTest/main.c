#include <stdio.h>
#include <stdlib.h>

int main()
{
    int iterations;

    scanf("%d", iterations);

    int result = 0;
    int i = 0;

    for(i = 0; i < iterations; i++){ //variable cycle
        result += bicyclePow(2, i); //sends it to makeshift pow
    }

    printf(result);

    return 0;
}

int bicyclePow(int num, int power){ //DIY pow, yay!
    int i = 0;
    int result = num - 1;
    for(i = 0; i < power; i++){
        result*=num;
    }
    return(result);
}
