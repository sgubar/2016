#include <stdio.h>
#include <stdlib.h>
#include "InputFunctions.h"
#pragma warning(disable : 4996)

void main()
{
	char c[5];
	char buffer[5];
	FILE *fptr;
	FILE *out;
	if ((fptr = fopen("in.txt", "r")) == NULL) {
		printf("Error! opening in file");
		exit(1);         /* Program exits if file pointer returns NULL. */
	}

	if ((out = fopen("out.txt", "w")) == NULL) {
		printf("Error! opening out file");
		exit(1);         /* Program exits if file pointer returns NULL. */
	}

	printf("Your file in.txt\n");
	fscanf(fptr, "%s", c);

	fscanf(fptr, "$s", c);
	for (int i = 0; i < 5; i++) {
		buffer[i] = c[5 - i];
	}
	fputs(buffer, out);

	printf("%s\n", c);
	fscanf(fptr, "%s", c);
	for (int i = 0; i < 5; i++) {
		buffer[i] = c[5 - i];
	}
	fputs(buffer, out);
	printf("%s\n", c);
	fscanf(fptr, "%s", c);
	for (int i = 0; i < 5; i++) {
		buffer[i] = c[5 - i];
	}
	fputs(buffer, out);
	printf("%s", c);

	right();

	getchar();
	getchar();
	
}

