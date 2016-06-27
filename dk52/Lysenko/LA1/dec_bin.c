#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "dec_bin.h"

void dec_bin(long dec_bin_Number)
{
	// Inizializaciya
	int cell = 0, invertBinary[65];

	// Perevod iz dec v bin
	for (cell; dec_bin_Number >= 1; cell++)
	{
		invertBinary[cell] = dec_bin_Number % 2; // Zapisyvaem ostatok deleniya v massiv
		dec_bin_Number /= 2;
	}
	// Dobavlyaem poslednij ostatok ot deleniya, esli ono ne ravno 0
	if (dec_bin_Number == 1) {
		invertBinary[cell] = dec_bin_Number;
	}
	else {
		cell--;
	}

	// Vyvod na ekran v obratnoj posledovatelnosti
	printf("Binary equivalent of number is:\n");
	for (cell; cell >= 0; cell--)
	{
		printf("%d", invertBinary[cell]);
	}
	printf("\n");

	// Ne daem zakrit consol
	system("pause");
	printf("\n");
	printf("\n");
	system("cls");
	main();
}
