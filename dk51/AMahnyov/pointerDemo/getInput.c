#include <stdio.h>
#include <stdlib.h>
#include "getInput.h"

int* getInput(int argNum);

int* getInput(int argNum){
    const int anArgNum = argNum;
    static int answer[anArgNum];
    int i;
    for(i = 0; i < argNum; i++){
        printf("Write an argument [%d]: ", i);
        scanf("%d", &answer[i]);
    }
    return(answer);
}
