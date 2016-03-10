#define _CRT_SECURE_NO_WARNINGS

#include<locale.h>  
#include <stdio.h>
#include <math.h>
#include "formula.h"

void main() {
	
	setlocale(LC_ALL, "RUS"); //localization
	float B, Q;
	int A = 0;

	printf("\tThis programm calculate Q<-(A!)/(A*2+B). \n\n");
	printf("Enter the A(greater than 0): ");
	scanf("%d", &A);
	
	if (A <= 0) {
		printf("\tError. Must be integer > 0.\n");
	}
	else {

		printf("Enter a float value (,) B: ");
		scanf_s("%f", &B);
		
		if (B > 0) {
			if ((A * 2 + B) == 0) {
				printf("\n\tError.\n\n");
			}
			else {
				Q = formula(A, B);
				printf("\n\tResult Q = %f\n", Q);
			}
		}
		else {
			printf("\n\tError. B - not a number\n");
		}
	}
		
	getch(); 
}