//
//  Lab1.4
// 
//
//  Created by Nazar Bronnikov on 09/03/16.
//  Copyright (C) 2016 Nazar Bronnikov. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include "suma.h"
#include "drob.h"

void main(void) {

	float A, B, C, D = 0, W, K;

	printf("A = ");
	scanf_s("%f", &A);

	printf("B = ");
	scanf_s("%f", &B);

	printf("C = ");
	scanf_s("%f", &C);

	K = suma(A, D) + drob(A, B, C);

	if (B + C != 100) {
		//printf("%f\n", (suma(A, D)));

		//printf("%f\n", (drob(A, B, C)));

		printf("%f\n", K);

		scanf_s("%f",&W);
	}
	else {
		printf("ERROR");
	}

	return 0;
}


