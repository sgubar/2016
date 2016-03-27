#include <stdio.h>
#include <conio.h>
#include <stdlib.h> //exit
#include <locale.h>
#include "hex_converter.h"
#include "start.h"
#include "error_log.h"
#include "countsigma.h"

void readarr() {//заполнение массива а[i], который "является" шестнадцатеричным числом F 
	for (int i = 0; i<21; i++) {
		a[i] = _getch();
		if (a[i] == 13) {
			length = i - 1;
			break;
		};
		printf("%c", a[i]);
		if (i == 20) length = 20;
	};
};

int funcforF(int dec, int stepen) {		//функция возведения в степень и суммирования разрядов шестнадцатеричного числа F
	int result = 16;

	if (stepen == 1) {                  //рассмотриваем степени 1 и 0 ка отдельные случаи
		F_dec = F_dec + (dec * 16);
		return 0;
	};

	if (stepen == 0) {
		F_dec = F_dec + (dec * 1);
		return 0;
	};

	for (int j = 1; j<stepen; j++) {    //остальные степени (предусмотрены натуральные степени) 
		result = result * 16;
	};

	F_dec = F_dec + (dec*result);

	return 1;
};

void elements() { //перевод каждого сивола числа F в число
	for (int i = length; i > -1; i--)
		switch (a[i]) {
		case 'F':
			funcforF(15, length-i);
			break;
		case 'E':
			funcforF(14, length - i);
			break;
		case 'D':
			funcforF(13, length - i);
			break;
		case 'C':
			funcforF(12, length - i);
			break;
		case 'B':
			funcforF(11, length - i);
			break;
		case 'A':
			funcforF(10, length - i);
			break;
		case '0':
			funcforF(0, length - i);
			break;
		case '1':
			funcforF(1, length - i);
			break;
		case '2':
			funcforF(2, length - i);
			break;
		case '3':
			funcforF(3, length - i);
			break;
		case '4':
			funcforF(4, length - i);
			break;
		case '5':
			funcforF(5, length - i);
			break;
		case '6':
			funcforF(6, length - i);
			break;
		case '7':
			funcforF(7, length - i);
			break;
		case '8':
			funcforF(8, length - i);
			break;
		case '9':
			funcforF(9, length - i);
			break;
		default:
			error_log(2); // выведение сообщения об ошибке
			break;
		};
};
