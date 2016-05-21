#include <stdio.h>
#include <stdlib.h>
#include "DynamicArray.h"
int main()
{
    int i=0;
DynamicIntArray * NewArr=createDAInt(10);
 infofunc(NewArr);
for(i;i<100;i++)
   setValueAtIndex(5,i,NewArr);
 infofunc(NewArr);
return 0;
}
