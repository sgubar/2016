#include <stdio.h>
#include <stdlib.h>
#include "InputFunctions.h"
#pragma warning(disable : 4996)

void main()
{
	do //Cycle of getting text from file and fool safity
	{
		printf("\tInput text to 'in.txt' and press Enter. \n\tDon't forget add enter symbol to end of text!");
		getchar();
	} while (!rightText());
	
	//Opening file "in.txt" with reading
	FILE *in;
	in = fopen("in.txt", "r");
	
    //initializing of variables
	char a[100];
	char buffer[100];
	char c;
	int i = 0;

	//reading text from file to a[100] by symbol
	while ((c = getc(in)) != EOF)
	{
		a[i] = c;
		i++;
	}
	
	//initialising the length of char massiv
	int length = i;
	a[length] = '\0';
	puts(a); //Shows a

	//Initialising variables to swap the chars in lines
	int count = 0;
	char memo = 0;
	int wordNum = 0;

	//Cycle of changing chars in lines
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
	
	//Shows buffer that contain swaped lines
	buffer[count] = '\0'; //Adding the end of buffer
	printf("\n");
	puts(buffer);

	right(); //Asking the user about correct result of program

	fclose(in); //closing file
	 
	getchar();
	
}

