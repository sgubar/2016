#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
void right() 
{
	char answer = 'f';
	printf("\nCorrect data?(Press y or n)");
	answer = getchar();
	if (answer != 'y')
	{
		printf("Change your file and restart the program!");
		getchar();
		getchar();
		exit(0);
	}
}
