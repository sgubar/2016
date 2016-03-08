#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "Input.h"

int doInput()
{
	extern int B, C, D;
	printf("Enter a number B\n");
	scanf("%d", &B);
	printf("Enter a number C\n");
	scanf("%d", &C);
	printf("Enter a number D\n");
	scanf("%d", &D);
	printf("%d %d %d\n", B, C, D);
	return (B,C,D);
}

