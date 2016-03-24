#include <stdio.h>
#include <conio.h>
#include <stdlib.h> //exit
#include <locale.h>
#include "redarr.h"
#include "check.h"
#include "read_and_prepare_hex_to_dec.h"

void readarr() {//zapolnyaem massiv a
	for (int i = 0; i<21; i++) {
		a[i] = _getch();
		if (a[i] == 13) {
			length = i - 1;
			break;
		};
		printf("%c", a[i]);
	};
    if (a[20]!=' '){
    	length=20;
    };
};

void replace() {
	short ereplace;
	char t;
	if (length % 2 != 0) ereplace = (length + 1) / 2; else ereplace = length / 2 + 1; //porogovoe znachenie tsikla s perestanovkoi

	for (int i = 0; i<ereplace; i++) {// tsikl zameni
		t = a[i];
		a[i] = a[length - i];
		a[length - i] = t;
	}
};

long fstepen(int stepen) {
	if (stepen == 1) return 16;
	if (stepen == 0) return 1;
	long result = 16;
	for (int j = 1; j<stepen; j++) {
		result = result * 16;
	};
	return result;
};

void elements() { //prohojdenie chisla(massiva) F
	for (int i = 0; i < length + 1; i++)
		switch (a[i]) {
		case 'F':
			funcforF(15, fstepen(i));
			break;
		case 'E':
			funcforF(14, fstepen(i));
			break;
		case 'D':
			funcforF(13, fstepen(i));
			break;
		case 'C':
			funcforF(12, fstepen(i));
			break;
		case 'B':
			funcforF(11, fstepen(i));
			break;
		case 'A':
			funcforF(10, fstepen(i));
			break;
		case '0':
			funcforF(0, fstepen(i));
			break;
		case '1':
			funcforF(1, fstepen(i));
			break;
		case '2':
			funcforF(2, fstepen(i));
			break;
		case '3':
			funcforF(3, fstepen(i));
			break;
		case '4':
			funcforF(4, fstepen(i));
			break;
		case '5':
			funcforF(5, fstepen(i));
			break;
		case '6':
			funcforF(6, fstepen(i));
			break;
		case '7':
			funcforF(7, fstepen(i));
			break;
		case '8':
			funcforF(8, fstepen(i));
			break;
		case '9':
			funcforF(9, fstepen(i));
			break;
		default:
			errorer(2);
			break;
	};
};

