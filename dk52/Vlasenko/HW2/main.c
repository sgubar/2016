//===============================================================
//				  Copyright by Olexandr Vlasenko.				 
//===============================================================

#include <stdio.h>
#include <time.h>

#include "Output.h"
#include "RewriteElement.h"
#include "AddElement.h"


int main()
{
	int answer, N, indx;
	printf("Enter the size of array: ");
	scanf_s("%d", &N);

	int *dynarray = (int*)calloc(N,sizeof(int)); // Allocating memory for array with N number of integer values.

	// Block of writing randomized values to dynamic array.
	srand(time(0));
	printf("Your array is:\n");
	for (indx = 0; indx < N; indx++)
	{
		dynarray[indx] = (rand() % 10 + 1);
		printf("%d\t", dynarray[indx]);
	}

	// Block of rewriting elements.
	answer = 1;
	while (answer)
	{
		printf("\nDo you want to rewrite a value at index? (write 0 or 1)\t");
		scanf_s("%d", &answer);
		if (answer == 0)
			break;
		RewriteElement(dynarray);
		Output(dynarray, N);
	}
	printf("As you wish :[");

	// Block of adding elements.
	answer = 1;
	while (answer)
	{
		printf("\nDo you want to add an element? (write 0 or 1)\t");
		scanf_s("%d", &answer);
		if (answer == 0)
			break;
		Output(AddElement(dynarray, indx, N), ++N);
	}
	printf("As you wish :[");

	realloc(NULL, dynarray); // Using "realloc" function instead of "free" function.
	printf("\n");
	system("pause");
	return 0;
}