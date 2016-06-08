#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "hex_oct.h"

void hex_oct()
{
	// Inizializaciya
	int hex_oct_Number;

	// Perevod iz hex v oct
	printf("Enter hexadecimal number:\n");
	scanf("%x", &hex_oct_Number);
	printf("Octal equivalent of number is %o\n", hex_oct_Number);

	// Ne daem zakrit consol
	system("pause");
	printf("\n");
	printf("\n");
	system("cls");
	main();
}
