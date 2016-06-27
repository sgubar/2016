#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "oct_hex.h"

void oct_hex()
{
	// Inizializaciya
	int oct_hex_Number;

	// Perevod iz oct v hex
	printf("Enter octal number:\n");
	scanf("%o", &oct_hex_Number);
	printf("Hexademical equivalent of number is %x\n", oct_hex_Number);

	// Ne daem zakrit consol
	system("pause");
	printf("\n");
	printf("\n");
	system("cls");
	main();
}
