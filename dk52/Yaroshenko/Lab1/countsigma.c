#include <stdio.h>
#include <conio.h>
#include <stdlib.h> //exit
#include <locale.h>
#include "hex_converter.h"
#include "start.h"
#include "error_log.h"
#include "countsigma.h"

void countsigma() {
	for (int i = 1; i<D + 1; i++) {
		sigma = sigma + i;
	};
};
