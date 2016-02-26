#include "getInput.h"
#include <stdio.h>

int getInput(){
    int i;
    int arguments[2];
    printf("Enter the input values, with space separation: \n");
    scanf("%d %d %d", &arguments[0], &arguments[1], &arguments[2]);
    return(arguments);
}
