#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>
#include "shellSort.h"
#include "SimpleSort.h"

static int *generateArray(int size);
static void printInput(int *input, int size);

int main(){
    int *randArray = generateArray(10);
    int
}

static int *generateArray(int size){
    srand(time(NULL));
    int *anArray = (int *)malloc(sizeof(int)*size);
    for(int i = 0; i<size; i++){
        *(anArray + i) = rand() %1000;
    }
    return anArray;
}

static void printInput(int *input, int size){
    int i;
		for (i = 0; i < size; i++){
        printf("You gave: [%d] as [%d]\n", i, input[i]);
    }
}
