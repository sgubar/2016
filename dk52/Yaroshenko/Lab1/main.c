#include <stdio.h>
#include <conio.h>
#include <stdlib.h> //exit
#include <locale.h>
#include "check.h"
#include "read_and_prepare_hex_to_dec.h"
#include "start.h"
#include "countsigma.h"

char a[20]; //maximalniy masiv
short length = 1;// realniy razmer massiva
int C, D; //nashi intovie peremennie
char F; //hex variable
long F_dec = 0;// peredelannoe chislo
int sigma = 0;

void main(){

	start();
	replace();
	elements();
	countsigma();
	printf("\nAnswer : %d\n", (F_dec - C)*sigma);
};
