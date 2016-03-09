

#include <stdio.h>
#include <stdlib.h>
#include "Function.h"

int FCTRL (int B);
int PWR (int C);


int FCTRL (int B)
{
int i;
int k=1;
for (i=B; i!=1; i--)
{
    k=k*i;
}
return (k);
}

int PWR (int C)
{
int j;
int m=1;
for (j=0; j!=C; j++)
{
 m=m*5;
}
return (m);
}

