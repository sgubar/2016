#include <stdio.h>
#include <stdlib.h>
#include "dynArray.h"

int main(){
    dynamicArray *testDynArray = createDynArray(3);
    writeToDA(testDynArray, 0, 1);
    writeToDA(testDynArray, 1, 6);
    writeToDA(testDynArray, 2, 4);
    printf("%d\n", readFromDA(testDynArray, 0));
    printf("%d\n", readFromDA(testDynArray, 1));
    printf("%d\n", readFromDA(testDynArray, 2));
    printf("Done!\n");
    return 0;
}
