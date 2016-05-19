//
//  main.c
//  demoSimpleSort
//
//  Created by Slava Gubar on 4/7/16.
//  Copyright В© 2016 Slava Gubar. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include "SimpleSort.h"
#include "shellSort.h"
#include "quickSort.h"

#define ARRAY_SIZE 10000

static void printArray(int* anArray, int aSize);
static void fillArray(int anArray[], int aSize, int aPivot);
int * CreateFilledArr(int aSize, int range);
int* CopyArr(int* FilledArray,int size);


int main(int argc, const char * argv[])
{
    int* array=CreateFilledArr(ARRAY_SIZE,150);
	
           	
	printArray(array,ARRAY_SIZE);
        
        printf("\nTest Selection sorting\n");
        clock_t theStart0 = clock();
	selectionSort(CopyArr(array,ARRAY_SIZE), ARRAY_SIZE);
	clock_t theEnd0 = clock();
	printf ("time of Selection sorting: %.10lf\n", (double)(theEnd0 - theStart0));
        printf("Clocks per sec %d",CLOCKS_PER_SEC);
		
	printf("\nTest Bubble sorting\n");
        
        clock_t theStart1 = clock();
        bubbleSort(CopyArr(array,ARRAY_SIZE), ARRAY_SIZE);
        clock_t theEnd1 = clock();
        printf("time of Bubble sorting: %.10lf\n",((double)(theEnd1-theStart1))/CLOCKS_PER_SEC);
        
        printf("\nTest Insertion sorting\n");
        
        clock_t theStart2 = clock();
        insertionSort(CopyArr(array,ARRAY_SIZE), ARRAY_SIZE);
        clock_t theEnd2 = clock();
        printf("time of Insertion sorting: %.10lf\n",(double)(theEnd2-theStart2)/CLOCKS_PER_SEC);
        
        printf("\nTest Shell sorting\n");
		
	clock_t theStart3 = clock();
	shellSort(CopyArr(array,ARRAY_SIZE), ARRAY_SIZE);
	clock_t theEnd3 = clock();
	
        printf ("time of Shell sorting: %.10lf\n", (double)(theEnd3 - theStart3)/CLOCKS_PER_SEC);
        
        
        printf("\nTest Quick sorting\n");
	clock_t theStartQuick = clock();
	quickSort2(CopyArr(array,ARRAY_SIZE), 0, ARRAY_SIZE - 1);
	clock_t theEndQuick = clock();
		
	printf ("time of Quick sorting: %.10lf\n", (double)(theEndQuick - theStartQuick)/CLOCKS_PER_SEC);

	printf("Hello, World!\n");
        
        free(array);
        
                int step=100,NumElm;
        double time;
        int* Arr;
        FILE* table;
        
        
        
         table = fopen("Bubble.csv", "w");
        printf("\nBubbleSort Advanced test\n");
           

    for(NumElm=500;NumElm<=60000;NumElm+=step)
    { 
        printf("test %d elements\n",NumElm);
        Arr=CreateFilledArr(NumElm,150);
        
        clock_t Start=clock();
        bubbleSort(Arr,NumElm);
        clock_t End=clock();
                      
        fprintf(table, "%d%;%.3lf\n",NumElm,(double)(End-Start)/CLOCKS_PER_SEC);
        step*=1.5;
       free(Arr);

    }
        
printf("Done!\n");       
fclose(table);        

  step=100;      
     table = fopen("Insertion.csv", "w");
        printf("\nInsertionSort Advanced test\n");
           

    for(NumElm=500;NumElm<=60000;NumElm+=step)
    { 
        printf("test %d elements\n",NumElm);
        Arr=CreateFilledArr(NumElm,150);
        
        clock_t Start=clock();
        insertionSort(Arr,NumElm);
        clock_t End=clock();
                      
        fprintf(table, "%d%;%.3lf\n",NumElm,(double)(End-Start)/CLOCKS_PER_SEC);
        step*=1.5;
       free(Arr);

    }
        
printf("Done!\n");       
fclose(table); 

step=100;
   table = fopen("Seletion.csv", "w");
        printf("\nSelectionSort Advanced test\n");
           

    for(NumElm=500;NumElm<=60000;NumElm+=step)
    { 
        printf("test %d elements\n",NumElm);
        Arr=CreateFilledArr(NumElm,150);
        
        clock_t Start=clock();
        selectionSort(Arr,NumElm);
        clock_t End=clock();
                      
        fprintf(table, "%d%;%.3lf\n",NumElm,(double)(End-Start)/CLOCKS_PER_SEC);
        step*=1.5;
       free(Arr);

    }
        
printf("Done!\n");       
fclose(table);      

step=100;
   table = fopen("Shell.csv", "w");
        printf("\nShellSort Advanced test\n");
           

    for(NumElm=500;NumElm<=1000000;NumElm+=step)
    { 
        printf("test %d elements\n",NumElm);
        Arr=CreateFilledArr(NumElm,150);
        
        clock_t Start=clock();
        shellSort(Arr,NumElm);
        clock_t End=clock();
                      
        fprintf(table, "%d%;%.3lf\n",NumElm,(double)(End-Start)/CLOCKS_PER_SEC);
        step*=1.5;
       free(Arr);

    }
        
printf("Done!\n");       
fclose(table);        

step=100;
        
          table = fopen("Quick.csv", "w");
        printf("\nQuickSort Advanced test\n");           

    for(NumElm=500;NumElm<=1000000;NumElm+=step)
    { 
        printf("test %d elements\n",NumElm);
        Arr=CreateFilledArr(NumElm,150);
        
        clock_t Start=clock();
        quickSort2(Arr,0,NumElm);
        clock_t End=clock();
                      
        fprintf(table, "%d%;%.3lf\n",NumElm,(double)(End-Start)/CLOCKS_PER_SEC);
        step*=1.5;
       free(Arr);

    }
        
printf("Done!\n");       
fclose(table);        
 
        
        
	return 0;
        
}


void printArray(int *anArray, int aSize)
{
	printf("{");
	for (int i = 0; i < aSize; i++)
	{
		printf(" %d ", anArray[i]);
	}

	printf("}\n");
}


int * CreateFilledArr(int aSize, int range)
{
     int *FldArr=malloc(aSize*sizeof(int));
     for (int i =0;i<aSize;i++)
    {
        FldArr[i]=rand() % (2*range);
    }
     return FldArr;
}

int* CopyArr(int* FilledArray,int size)
{
    
    int *CopiedArr=malloc(size*sizeof(int));
   
    for (int i =0;i<size;i++)
    {
        CopiedArr[i]=FilledArray[i];
    }
    
    return CopiedArr;
}

