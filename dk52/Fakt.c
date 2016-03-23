//
//  Fakt.c
//  lab1
//
//  Created by Nazar Koshariuk on 3/10/16.
//  Copyright © 2016 Nazar Koshariuk. All rights reserved.
//
#include <stdio.h>
#include "Fakt.h"
int i,Fakto=1;
void doFakt(int ParamB, int ParamD){
 for (i=ParamD+1; i<ParamB+1;i++){
	Fakto=Fakto*i;
	}


 return 0;
}