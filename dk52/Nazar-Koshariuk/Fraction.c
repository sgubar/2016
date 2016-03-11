//
//  Fraction.c
//  lab1
//
//  Created by Nazar Koshariuk on 3/10/16.
//  Copyright © 2016 Nazar Koshariuk. All rights reserved.
//
#include <stdio.h>
#include "Fraction.h"
float Frac;
void doFraction(int ParamA, int ParamB, int ParamC){
	Frac=(float)(ParamA * ParamB) / (float)(ParamB+(ParamC * ParamC));
	return 0;
}