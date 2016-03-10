#define _CRT_SECURE_NO_WARNINGS

#include<locale.h>  
#include <stdio.h>
#include <math.h>
#include "formula.h"

void main() {
	
	setlocale(LC_ALL, "RUS"); //включає підтримку кирилиці
	float B, Q;
	int A = 0;

	printf("\tЦя програма рахує Q<-(A!)/(A*2+B). \n\n");
	printf("Введiть цiле число A(бiльше 0): ");
	scanf("%d", &A);
	
	if (A <= 0) {
		printf("\tПомилка. А повинне бути цiлим числом > 0.\n");
	}
	else {

		printf("Введiть число з плаваючою КОМОЮ(,) B: ");
		scanf_s("%f", &B);
		
		if (B > 0) {
			if ((A * 2 + B) == 0) {
				printf("\n\tПомилка. Дiльник = 0\n\n");
			}
			else {
				Q = formula(A, B);
				printf("\n\tРезультат Q = %f\n", Q);
			}
		}
		else {
			printf("\n\tПомилка. B - не число\n");
		}
	}
		
	getch(); 
}