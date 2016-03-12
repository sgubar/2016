#include <stdio.h>
#include <stdlib.h>
#include "getInput.h"

int* getInput(int argNum);

int* getInput(int argNum){
    int answer[argNum];
    int i;
    for(i = 0; i < argNum; i++){
        printf("Write an argument [%d]: ", i);
        scanf("%d", &answer[i]);
    }
    return(answer);
}
