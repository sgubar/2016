
//  main.c 
//  laba1
// 
//  Created by Bogdan Maximovich on 8/03/16. 
//  Copyright (C) 2016 Bogdan Maximovich. All rights reserved. 

#include "Header.h"

int fac(int n) {   //фактор≥ал числа n
	int k = 1;  
	for (int i = 1; i <= n; i++) //поки ≥ буде менше або дор≥внювати n винонуЇтьс€ умова, ≥ зб≥льшуЇтьс€ на 1
		k *= i; //поки ≥ менше n виконуЇтьс€ ц€ умова
	return k;
}

double f(int a, int b, int c) {
	double q = 0;
	q += (double)(a*b) / (b + c*c);
	for (int i = 0; i <= b; i++) q += fac(i); //на кожне повторенн€ циклу до q додаЇтьс€ значенн€ €ке повертаЇ функц≥€ fac
	return q;
}