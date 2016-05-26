#include <time.h>
#include "sort_lib.h"
#include <stdlib.h>

void test_perfomance_bubbleSort(int *testArray, int size)
{
    clock_t time_before, time_after;
    time_before =  clock();
    bubbleSort(testArray, size);
    time_after = clock();
    float timeTook = (float)(time_after - time_before)/CLOCKS_PER_SEC;
    printf("Bubble sort on array of int[1000] : %13.6f sec\n", timeTook);

}

void test_perfomance_selectionSort(int *testArray, int size)
{
    clock_t time_before, time_after;
    time_before =  clock();
    selectionSort(testArray, size);
    time_after = clock();
    float timeTook = (float)(time_after - time_before)/CLOCKS_PER_SEC;
    printf("Selection sort on array of int[1000] : %10.6f sec\n", timeTook);

}

void test_perfomance_insertionSort(int *testArray, int size)
{
    clock_t time_before, time_after;
    time_before =  clock();
    insertionSort(testArray, size);
    time_after = clock();
    float timeTook = (float)(time_after - time_before)/CLOCKS_PER_SEC;
    printf("Insertion sort on array of int[1000] : %10.6f sec\n", timeTook);

}

void test_perfomance_shellSort(int *testArray, int size)
{
    clock_t time_before, time_after;
    time_before =  clock();
    shellSort(testArray, size);
    time_after = clock();
    float timeTook = (float)(time_after - time_before)/CLOCKS_PER_SEC;
    printf("Shell sort on array of int[1000] : %14.6f sec\n", timeTook);

}
