#include <stdio.h>
#include <conio.h>
#include <stdlib.h> //exit
#include <locale.h>
#include "check.h"
#include "read_and_prepare_hex_to_dec.h"
#include "start.h"
#include "countsigma.h"

void countsigma() {
	for (int i = 1; i<D + 1; i++) {
		sigma = sigma + i;
	};
};
