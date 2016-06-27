#define _CRT_SECURE_NO_WARNINGS
#include"Sorting.h"
#include"function.h"
#include<stdio.h>
#include<time.h>



void printArray(int anArray[], int aSize);

int main()
{
	int choice = 0;
	while (1) {
		printf("Choice size of array\n Please enter coresponding bottom\n 1) 500\n 2) 1000\n 3) 10000\n 4) 40000\n or exit 0\n");
		scanf("%i", &choice);
		switch (choice)
		{
		case 1:
			Sort1();
			break;
		case 2:
			Sort2();
			break;
		case 3:
			Sort3();
			break;
		case 4:
			Sort4();
			break;
		case 0:
			exit(0);
			break;
		default:
			printf("Uncorrect choice, Please try again\n");
			break;
		}
	}
	return 0;
	system("pause");
}

void printArray(int anArray[], int aSize)
{
	printf("{");
	for (int i = 0; i < aSize; i++)
	{
		printf(" %d ", anArray[i]);
	}

	printf("}\n");
}
