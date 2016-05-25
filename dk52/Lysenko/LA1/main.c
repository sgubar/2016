#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "dec_bin.h"
#include "hex_oct.h"
#include "oct_hex.h"

	int main()
{
	// Spisok operaciy
	printf("Choose operation:\n");
	printf("1. Translation from decimal to binary\n");
	printf("2. Translation from binary to decimal\n");
	printf("3. Translation from hexadecimal to octal\n");
	printf("4. Translation from octal to hexadecimal\n");
	printf("5. Exit\n");
	printf("\n");

	int operation;
	long dec_bin_Number, bin_dec_Number;
	// Vibiraem operaciyu
	do {
		printf("Enter number of operation:\n");
		scanf("%d", &operation);
		printf("\n");
	} while (operation != 1 && operation != 2 && operation != 3 && operation != 4 && operation != 5);
	// Vivod vibrannoi operacii na ekran
	if (operation == 1) {
		do {
			printf("Enter decimal number:\n");
			scanf("%ld", &dec_bin_Number);
		} while (dec_bin_Number < 0);
		dec_bin(dec_bin_Number);
	}
	else if (operation == 2) {
		printf("Enter binary number:\n");
		scanf("%ld", &bin_dec_Number);
		bin_dec(bin_dec_Number);
	}
	else if (operation == 3) {
		hex_oct();
	}
	else if (operation == 4) {
		oct_hex();
	}
	else if (operation == 5) {
		return 0;
	}
	return 0;
}
