#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Sort.h"
#include "shellSort.h"

const int A_Size=10000;
const int B_Size=1000;

//static void printArray(int anArray[], int aSize);
int** NewArr(int Size){
	int** N = (int**) malloc(4 * sizeof(int*));
	int i;
	for(i=0;i<4;i++)
		N[i]=(int*) malloc(Size * sizeof(int));
	srand(time(NULL));
	for(i=0;i<Size;i++){
		N[0][i]=rand();
		int j;
		for(j=1;j<4;j++)
			N[j][i]=N[0][i];
	}
	return N;
}
int main()
{
	int** Arr=NewArr(B_Size);
	int** MArr=NewArr(A_Size);
	clock_t S,E;
	//Bubble sort
	S = clock();
	bubble(Arr[0], B_Size);
	E = clock();
	printf("Bubble sorting for 1000: %.10lf sec\n", 1.*(E - S) / CLOCKS_PER_SEC);
	
	S = clock();
	bubble(MArr[0], A_Size);
	E = clock();
	printf("Bubble sorting for 10000: %.10lf sec\n", 1.*(E - S) / CLOCKS_PER_SEC);

	//Selection sort
	S = clock();
	Tsort(Arr[0], B_Size);
	E = clock();
	printf("Choice sorting for 1000: %.10lf sec\n", 1.*(E - S) / CLOCKS_PER_SEC);
	
	S = clock();
	Tsort(MArr[1], A_Size);
	E = clock();
	printf("Choice sorting for 10000: %.10lf sec\n", 1.*(E - S) / CLOCKS_PER_SEC);

	//Insertion sort
	S = clock();
	Psort(Arr[0], B_Size);
	E = clock();
	printf("Piece sorting for 1000: %.10lf sec\n", 1.*(E - S) / CLOCKS_PER_SEC);
	
	S = clock();
	Psort(MArr[2], A_Size);
	E = clock();
	printf("Piece sorting for 10000: %.10lf sec\n", 1.*(E - S) / CLOCKS_PER_SEC);

	//Shell sort
	S = clock();
	shellSort(Arr[0], B_Size);
	E = clock();
	printf("Shell sorting for 1000: %.10lf sec\n", 1.*(E - S) / CLOCKS_PER_SEC);
	
	S = clock();
	shellSort(MArr[3], A_Size);
	E = clock();
	printf("Shell sorting for 10000: %.10lf sec\n", 1.*(E - S) / CLOCKS_PER_SEC);

	return 0;
}
