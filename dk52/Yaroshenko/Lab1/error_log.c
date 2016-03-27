#include <stdio.h>
#include <conio.h>
#include <stdlib.h> //exit
#include <locale.h>
#include "hex_converter.h"
#include "start.h"
#include "error_log.h"
#include "countsigma.h"

void error_log(int value) {
	switch (value)
	{
	case 1:
		printf("\nD must be >= 1 \nRepeat input? y/n ");
		if (_getch() == 121) {
			printf("Enter decimal D: "); scanf_s("%d", &D); if (D <= 1) error_log(1); break;
		};
		exit(1);
	case 2:
		printf_s("\nerr input HEX digit\n"); exit(1);


		exit(1);
	default:
		break;
	};
};
