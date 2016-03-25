#include <stdio.h>
#include <stdlib.h>
#include "InputFunctions.h"
#pragma warning(disable : 4996)

void main()
{
	do
	{
		printf("\tInput text to 'in.txt' and press Enter. \n\tDon't forget add enter symbol to end of text!");
		getchar();
	} while (!rightText());
	
	FILE *in;
	in = fopen("in.txt", "r");
	FILE *out;

	char a[100];
	char buffer[100];
	char c;
	int i = 0;
	while ((c = getc(in)) != EOF)
	{
		a[i] = c;
		i++;
	}
	
	int length = i;
	a[length] = '\0';
	puts(a);

	int count = 0;
	char memo = 0;
	int wordNum = 0;
	while(count != length)
	{
		while ((a[count] != '\n')) count++;
		for (int index = 0; index < count-memo; index++)
		{
			buffer[count - index - 1 ] = a[index+wordNum+memo];
		}
		
		
		
		buffer[count] = '\n';
		memo = count;
		wordNum = 1;
		count++;
	}
	buffer[count] = '\0';
	printf("\n");
	puts(buffer);

	right();

	fclose(in);

	getchar();
	
}

