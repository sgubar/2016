#include <stdio.h>

void scanString(char *string, int maxLength)
{
	for(int limit = 0; ((*string++) = getchar())!='\n'&&limit < maxLength; limit++);
	*--string = '\0';
}

void printString(char *string)
{
	while(*string)
	putchar(*string++);
}



