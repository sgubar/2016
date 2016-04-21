#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>
extern "C" {
#include "shellSort.h"
#include "SimpleSort.h"
}

static int *generateArray(int size);
static float runTest(int sortType, int arrSize);
static void printArray(int anArray[], int aSize);


int main(){
    printf("Starting sorting comparation.\n");
//    printf("%.10f\n", runTest(0, 10000));
//    printf("%.10f\n", runTest(1, 10000));
//    printf("%.10f\n", runTest(2, 10000));
//    printf("%.10f\n", runTest(3, 10000));
    printf("Launching graphics...\n");
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, "");
    setviewport(0, 0, getmaxx(), getmaxy(), 0);
    int k = (getmaxy())/runTest(0, 10000);
    for(int z = 0; z<=3; z++){
        switch(z){
            case 0: printf("Bubble - red\n"); setcolor(RED); break;
            case 1: printf("Selection - blue\n"); setcolor(BLUE); break;
            case 2: printf("Insertion - green\n"); setcolor(GREEN); break;
            case 3: printf("Shell - yellow\n"); setcolor(YELLOW); break;
        }
        float value3 = runTest(z, 10000);
        float value2 = runTest(z, 8000);
        float value1 = runTest(z, 5000);
        float value0 = runTest(z, 2000);
        //x1 y1 x2 y2
        line(0, getmaxy(), getmaxx()/4, (int)(getmaxy()-value0*k));
        line(getmaxx()/4, (int)(getmaxy()-value0*k), getmaxx()*2/4, (int)(getmaxy()-value1*k));
        line(getmaxx()*2/4, (int)(getmaxy()-value1*k), getmaxx()*3/4, (int)(getmaxy()-value2*k));
        line(getmaxx()*3/4, (int)(getmaxy()-value2*k), getmaxx(), (int)(getmaxy()-value3*k));
        moveto(0, getmaxy());
    }
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

static float runTest(int sortType, int arrSize){
    int *testArray = generateArray(arrSize);
    clock_t start0 = clock();
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

static void printArray(int anArray[], int aSize)
{
	printf("{");
	for (int i = 0; i < aSize; i++)
	{
		printf(" %d ", anArray[i]);
	}

	printf("}\n");
}
