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
int* Copypast(int* SortArr,int aSize);
int main(int argc, const char * argv[])
{
         int i;
         int aSize;
        printf ("Enter the length of mass:");
        scanf("%d", &aSize);
        
        
      	printf("Test bubble sorting\n");
	int *NotSortArr=randArray(aSize);
        int* BubbleAr=Copypast(NotSortArr,aSize);
        //printArray(BubbleAr,aSize);
        clock_t StartBubble=clock();
	bubbleSort(BubbleAr,aSize);
        clock_t EndBubble=clock();
        //printArray(BubbleAr,aSize);
        printf ("time of Bubble sorting: %.12lf\n", (double)(EndBubble - StartBubble)/CLOCKS_PER_SEC);
	
        printf("\nTest selection sorting\n");
        int* SelAr=Copypast(NotSortArr,aSize);
        //printArray(SelAr,aSize);
        clock_t StartSel=clock();
	selectionSort(SelAr,aSize);
        clock_t EndSel=clock();
        printf ("time of Selection sorting: %.12lf\n", (double)(EndSel - StartSel)/CLOCKS_PER_SEC);	

	printf("\nTest insertion sorting\n");
	int* InsAr=Copypast(NotSortArr,aSize);
        //printArray(InsAr,aSize); 
        clock_t InsStart=clock();
	insertionSort(InsAr,aSize);
        clock_t InsEnd=clock();
        
	printf ("time of Insertion sorting: %.12lf\n", (double)(InsEnd - InsStart)/CLOCKS_PER_SEC);

	printf("\nTest Shell sorting\n");
	int* ShellAr=Copypast(NotSortArr,aSize);
         //printArray(ShellAr,aSize); 
        clock_t StartShell=clock();
	shellSort(ShellAr,aSize);
        clock_t EndShell=clock(); 
	
	printf ("time of Shell sorting: %.12lf\n", (double)(EndShell - StartShell)/CLOCKS_PER_SEC);
	
		
	printf("\nTest Quick sorting\n");
        
	int* QuickAr=Copypast(NotSortArr,aSize);
          //printArray(QuickAr,aSize); 
        clock_t StartQuick=clock();
	quickSort2(QuickAr,0,aSize);
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

int* Copypast(int* SortArr,int aSize) 
{ 

int *Copypast=malloc(aSize*sizeof(int)); 

for (int i =0;i<aSize;i++) 
{ 
Copypast[i]=SortArr[i]; 
} 

return Copypast; 
}
