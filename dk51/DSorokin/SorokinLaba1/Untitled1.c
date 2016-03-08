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

int doFactorial (int B);
int doPower(int C);


int doFactorial (int B)
{
int i;
int k=1;
for (i=B; i!=1; i--)
{
    k=k*i;
}
return (k);
}

int doPower(int C)
{
int j;
int m=1;
for (j=0; j!=C; j++)
{
 m=m*5;
}
return (m);
}

