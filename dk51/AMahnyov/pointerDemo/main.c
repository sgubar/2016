#include <stdio.h>
#include <stdlib.h>
#include "getInput.h"

static void printInput(int *input);

int main(){
    int argNum = 0;
    printf("How many arguments do you want?\n");
    scanf("%d", &argNum);

    int *recievedAnswer;

    recievedAnswer = getInput(argNum);

    printInput(recievedAnswer);

    return 0;
}

void printInput(int *input){
    int i;
    for(i = 0; i<sizeof(input); i++){
        printf("You gave: [%d] as [%d]\n", i, input[i]);
    }
}
