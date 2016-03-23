#include <stdio.h>
#include <conio.h>
#include <stdlib.h> //exit
#include <locale.h>
#include "check.h"
#include "read_and_prepare_hex_to_dec.h"
#include "start.h"
#include "countsigma.h"

void start() {// privetsvie i vvod chisla
	printf("Введите  десятичные число С: "); scanf_s("%d", &C);
	printf("Введите  десятичное число D: "); scanf_s("%d", &D); if (D < 1) are_u_dumb(1);
	printf("Введите  шестнадцетеричное число F: (ввод большими буквами)"); readarr(); //vizov funcii chteniya
};
