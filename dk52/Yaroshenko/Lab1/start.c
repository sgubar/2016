#include <stdio.h>
#include <conio.h>
#include <stdlib.h> //exit
#include <locale.h>
#include "hex_converter.h"
#include "start.h"
#include "error_log.h"
#include "countsigma.h"


void start() {// privetsvie i vvod chisla
	printf("Enter decimal С: "); scanf_s("%d", &C);
	printf("Enter decimal D: "); scanf_s("%d", &D); if (D < 1) error_log(1); //количество слагаемых не может быть меньше 1
	printf("Enter hexadecimal F: (write by caps)"); readarr(); //теперь эта функция должна принимать нащ массив
};
