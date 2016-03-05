#include<stdio.h>

#include"Math.h"

double Sub(int number, int C);
double Sub(int number, int C) {
	double Sub = 0;
	Sub = number - C;
	return(Sub);
	printf("Sub=%d\n", Sub);
	system("pause");
}