//
//  main.c
//  demoSimpleSort
//
//  Created by Slava Gubar on 4/7/16.
//  Copyright © 2016 Slava Gubar. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include "SimpleSort.h"
#include "shellSort.h"
#include "quickSort.h"
#include "random.h"

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))

void printArray(int anArray[], int aSize);

int main(int argc, const char * argv[])
{
         int i;
         int aSize;
        printf ("Enter the length of mass:");
        scanf("%d", &aSize);
        
      	printf("Test bubble sorting\n");
	int* BubArray= randArray (aSize);
        printArray(BubArray,aSize);
        clock_t StartBubble=clock();
	bubbleSort(BubArray,aSize);
        clock_t EndBubble=clock();
        printf ("time of Bubble sorting: %.12lf\n", (double)(EndBubble - StartBubble)/CLOCKS_PER_SEC);
	
        printf("\nTest selection sorting\n");
        int* SelArray= randArray (aSize);
        printArray(SelArray,aSize);
        clock_t StartSel=clock();
	selectionSort(SelArray,aSize);
        clock_t EndSel=clock();
        printf ("time of Selection sorting: %.12lf\n", (double)(EndSel - StartSel)/CLOCKS_PER_SEC);	

	printf("\nTest insertion sorting\n");
	int* InsArray= randArray (aSize);
         printArray(InsArray,aSize); 
        clock_t InsStart=clock();
	insertionSort(InsArray,aSize);
        clock_t InsEnd=clock();
        
	printf ("time of Insertion sorting: %.12lf\n", (double)(InsEnd - InsStart)/CLOCKS_PER_SEC);

	printf("\nTest Shell sorting\n");
	 int* ShellArray= randArray (aSize);
         printArray(ShellArray,aSize); 
        clock_t StartShell=clock();
	bubbleSort(ShellArray,aSize);
        clock_t EndShell=clock();
	
	printf ("time of Shell sorting: %.12lf\n", (double)(EndShell - StartShell)/CLOCKS_PER_SEC);
	
		
	printf("\nTest Quick sorting\n");
        
	 int* QuickArray= randArray (aSize);
          printArray(QuickArray,aSize); 
        clock_t StartQuick=clock();
	quickSort2(QuickArray,0,aSize);
        clock_t EndQuick=clock();
	
	printf ("time of Quick sorting: %.12lf\n", (double)(EndQuick - StartQuick)/CLOCKS_PER_SEC);
         
	printf("Finished!\n");
	

}

void printArray(int* anArray,int aSize)
{
     int i;
	printf("{");
	for (i = 0; i < aSize; i++)
	{
		printf(" %d ", anArray[i]);
	}

	printf("}\n");
}


