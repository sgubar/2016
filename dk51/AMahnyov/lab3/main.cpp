#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>
#include <locale>

extern "C" {
#include "shellSort.h"
#include "SimpleSort.h"
}

static int *generateArray(int size);
static float runTest(int sortType, const int theTestArray[], const int arrSize);
static void drawGraph(float inputArray[5][5]);
static void drawTable(float inputArray[5][5]);


int main(){

    printf("Starting sorting comparation.\n");
    int *theTestArray0 = generateArray(1000);
    int *theTestArray1 = generateArray(2000);
    int *theTestArray2 = generateArray(4000);
    int *theTestArray3 = generateArray(8000);
    int *theTestArray4 = generateArray(10000);
    float results[5][5] = {
    {runTest(0, theTestArray0, 1000), runTest(1, theTestArray0, 1000), runTest(2, theTestArray0, 1000), runTest(3, theTestArray0, 1000), runTest(3, theTestArray0, 1000)},
    {runTest(0, theTestArray1, 2000), runTest(1, theTestArray1, 2000), runTest(2, theTestArray1, 2000), runTest(3, theTestArray1, 2000), runTest(3, theTestArray1, 2000)},
    {runTest(0, theTestArray2, 4000), runTest(1, theTestArray2, 4000), runTest(2, theTestArray2, 4000), runTest(3, theTestArray2, 4000), runTest(3, theTestArray2, 4000)},
    {runTest(0, theTestArray3, 8000), runTest(1, theTestArray3, 8000), runTest(2, theTestArray3, 8000), runTest(3, theTestArray3, 8000), runTest(3, theTestArray3, 8000)},
    {runTest(0, theTestArray4, 10000), runTest(1, theTestArray4, 10000), runTest(2, theTestArray4, 10000), runTest(3, theTestArray4, 10000), runTest(3, theTestArray4, 10000)}
    };
    drawTable(results);
    system("pause");
    printf("Launching graphics...\n");
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, "");
    setviewport(0, 0, getmaxx(), getmaxy(), 0);
    drawGraph(results);
    system("pause");
    closegraph();
    return 0;
}


static int *generateArray(int size){
    srand(time(NULL));
    int *anArray = (int *)malloc(sizeof(int)*size);
    for(int i = 0; i<size; i++){
        *(anArray + i) = rand() %1000;
    }
    return anArray;
}

static float runTest(int sortType, const int theTestArray[], const int arrSize){
    clock_t start0 = clock();
    int testArray[arrSize];
    for(int i = 0; i<arrSize; i++){
        testArray[i] = theTestArray[i];
    }
    switch(sortType){
        case 0:
            bubbleSort(testArray, arrSize);
        break;
        case 1:
            selectionSort(testArray, arrSize);
        break;
        case 2:
            insertionSort(testArray, arrSize);
        break;
        case 3:
            shellSort(testArray, arrSize);
        break;
    }
    clock_t finish0 = clock();
    float timeTook = (float)(finish0 - start0)/CLOCKS_PER_SEC;
    return timeTook;
}

static void drawGraph(float inputArray[5][5]){
    int k = getmaxy()/inputArray[3][0];
    for(int z = 0; z<4; z++){
        switch(z){
            case 0: printf("Bubble - red\n"); setcolor(RED); break;
            case 1: printf("Selection - blue\n"); setcolor(BLUE); break;
            case 2: printf("Insertion - green\n"); setcolor(GREEN); break;
            case 3: printf("Shell - yellow\n"); setcolor(YELLOW); break;
        }
        float value0 = inputArray[0][z];
        float value1 = inputArray[1][z];
        float value2 = inputArray[2][z];
        float value3 = inputArray[3][z];
        //x1 y1 x2 y2
        line(0, getmaxy(), getmaxx()/4, (int)(getmaxy()-value0*k));
        line(getmaxx()/4, (int)(getmaxy()-value0*k), getmaxx()*2/4, (int)(getmaxy()-value1*k));
        line(getmaxx()*2/4, (int)(getmaxy()-value1*k), getmaxx()*3/4, (int)(getmaxy()-value2*k));
        line(getmaxx()*3/4, (int)(getmaxy()-value2*k), getmaxx(), (int)(getmaxy()-value3*k));
        moveto(0, getmaxy());
    }
}

static void drawTable(float inputArray[5][5]){
    printf("_____________________________________________________________________________\n");
    printf("|   DATA   |BubbleSort  |SelectionS  |InsterionS  |ShellSort   |QuickSort   |\n");
    printf("=============================================================================\n");
    printf("|   1000   |%.10f|%.10f|%.10f|%.10f|%.10f|\n", inputArray[0][0], inputArray[0][1], inputArray[0][2], inputArray[0][3], inputArray[0][4]);
    printf("=============================================================================\n");
    printf("|   2000   |%.10f|%.10f|%.10f|%.10f|%.10f|\n", inputArray[1][0], inputArray[1][1], inputArray[1][2], inputArray[1][3], inputArray[1][4]);
    printf("============================================================================\n");
    printf("|   4000   |%.10f|%.10f|%.10f|%.10f|%.10f|\n", inputArray[2][0], inputArray[2][1], inputArray[2][2], inputArray[2][3], inputArray[2][4]);
    printf("=============================================================================\n");;
    printf("|   8000   |%.10f|%.10f|%.10f|%.10f|%.10f|\n", inputArray[3][0], inputArray[3][1], inputArray[3][2], inputArray[3][3], inputArray[3][4]);
    printf("=============================================================================\n");
    printf("|  10000   |%.10f|%.10f|%.10f|%.10f|%.10f|\n", inputArray[4][0], inputArray[4][1], inputArray[4][2], inputArray[4][3], inputArray[4][4]);
    printf("=============================================================================\n");
}
