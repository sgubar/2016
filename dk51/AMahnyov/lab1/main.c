#include <stdio.h>
#include <stdlib.h>
#include "calculate.h"


int main(int argc, char *argv[])
{
    if(argc == 4){
        doFormula(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
    } else {
        printf("Invalid input! \nSyntax: 'lab1 <A> <B> <C>'");
    }
    return 0;
}

