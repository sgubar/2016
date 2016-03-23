#include <stdio.h>
#include <conio.h>
#include <stdlib.h> //exit
#include <locale.h>
#include "check.h"
#include "read_and_prepare_hex_to_dec.h"
#include "start.h"
#include "countsigma.h"

void are_u_dumb(int value) {
	switch (value)
	{
	case 1:
		printf("\nD must be >= 1 \nRepeat input? y/n ");
		if (_getch() == 121) {
			printf("Enter decimal D: "); scanf_s("%d", &D); if (D <= 1) are_u_dumb(1); break;
		};
		exit(1);
	case 2:
		printf("\nerr input HEX digit\n"); exit(1);


		exit(1);
	default:
		break;
	};
};
