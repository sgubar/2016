#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "searchFunctions.h"


int main(){
    srand(time(NULL));
    printf("Running sorting comparation.\nLine search, 1000 elements:\n");
    int *testArray = generateOrdArray(1000);
    int key = rand()%1000;
    clock_t startTime = clock();
    int result = line_find(testArray, 1000, key);
    clock_t finishTime = clock();
    if(errorCode == 0) printf("Found %d at index %d\n", key, result);
    else printf("Element %d not found\n", key);
    printf("Time took: %.13f\n", (float)(startTime - finishTime)/CLOCKS_PER_SEC);

    printf("Running sorting comparation.\nBinary search, 1000 elements:\n");
    clock_t binStartTime = clock();
    result = searchIn(testArray, 0, 1000, key);
    clock_t binFinishTime = clock();
    if(errorCode == 0) printf("Found %d at index %d\n", key, result);
    else printf("Element %d not found\n", key);
    printf("Time took: %.13f\n", (float)(binStartTime - binFinishTime)/CLOCKS_PER_SEC);
    return 0;
}


