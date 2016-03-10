#include <stdio.h>
#include <conio.h>


void enter1(int*A, int*B)
{ 
	do {
		printf("\n ENTER A: ");
		scanf("%d", &*A);
		printf("\n ENTER B: ");
		scanf("%d", &*B);
		if ((*A + *B * 2) == 0) 
			printf("\n ERROR: the denominator is zero, re-enter the values\n");
		if (*A < 0)
			printf("\n ERROR: A<0 re-enter the values\n");
	}
		while ((*A + *B * 2) == 0 || *A<0);
	
}
