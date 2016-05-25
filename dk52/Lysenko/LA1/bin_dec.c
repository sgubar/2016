#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "bin_dec.h"

void bin_dec(long bin_dec_Number)
{
	// Inizializaciya
	long decimal = 0, base = 1, remainder;

	// Perevod iz bin v dec
	for (base; bin_dec_Number > 0; base *= 2)
	{
		remainder = bin_dec_Number % 10;
		decimal = decimal + remainder * base;
		bin_dec_Number /= 10;
	}

	// Vivod na ekran
	printf("Decimal equivalent of number is:\n");
	printf("%d\n", decimal);

	// Ne dem zakrit consol
	system("pause");
	printf("\n");
	printf("\n");
	system("cls");
	main();
	
}
