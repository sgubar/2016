/*Copyright (c), 2016, Mahnyov Aleksander. All rights reserved*/
#include <stdio.h>
#include <stdlib.h>
#include "dynArray.h"

int main(){
    dynamicArray *testDynArray = createDynArray(2);
    //printf("Writing in bounds.\n");
    writeToDA(testDynArray, 0, 1);
    //writeToDA(testDynArray, 1, 6);
    //writeToDA(testDynArray, 2, 4);
    printf("%d\n", readFromDA(testDynArray, 0));
   // printf("%d\n", readFromDA(testDynArray, 1));
    //printf("%d\n", readFromDA(testDynArray, 2));
    //printf("Writing outside bounds\n");
    //writeToDA(testDynArray, 150, 134);
   // printf("%d\n", readFromDA(testDynArray, 150));
    //printf("Cleaning up\n");
    //freeDynArray(testDynArray);
    printf("Done!\n");
    return 0;
}
