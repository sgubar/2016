#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "test_sort_perf.h"

int *generateArray(int size){
    srand(time(NULL));
    int *anArray = (int *)malloc(sizeof(int)*size);
    for(int i = 0; i<size; i++){
        *(anArray + i) = 0 + rand() %1000;
    }
    return anArray;
}

int main()
{
    int array_size = 1000;
    int *testArray1 = generateArray(array_size);
    int *testArray2 = generateArray(array_size);
    int *testArray3 = generateArray(array_size);
    int *testArray4 = generateArray(array_size);


    printf("\tResults: \n\n");
    test_perfomance_bubbleSort(testArray1, array_size);
    test_perfomance_selectionSort(testArray2, array_size);
    test_perfomance_insertionSort(testArray3, array_size);
    test_perfomance_shellSort(testArray4, array_size);

    return 0;
}
