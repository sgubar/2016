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

bool rightText()
{
	FILE *in;
	in = fopen("in.txt", "r");

	int i=0; char c;
	char a[1000];
	while ((c = getc(in)) != EOF)
	{
		a[i] = c;
		i++;
	}
	if (a[i - 1] != '\n')
	{
		return false;
		printf("\n\t\t**You forget to add enter symbol to the end\n");
	}
	else return true;
	fclose(in);
}