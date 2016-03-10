//
//
//  Laboratorna1
//
//  Created by Sorokin Dmytro on 07/03/16.
//  Copyright © 2016 Sorokin Dmytro. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Untitled1.h"
#include "Untitle2.h"

int doFactorial (float bParam)
{
int i;
int k=1;
for (i=bParam; i!=1; i--)
{
    k=k*i;
}
return (k);
}

int doPower(float cParam)
{
int j;
int m=1;
for (j=0; j!=cParam; j++)
{
 m=m*5;
}
return (m);
}


