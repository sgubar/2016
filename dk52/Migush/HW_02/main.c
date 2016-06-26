        /////////////////////////////////////////////////////////
       //    main.c                                           //
      //                                                     //
     //   do test                                           //
    //                                                     //
   //   Created by Max Migush on 10/04/2016               //
  //                                                     //
 //  Copyright © 2016 Max Migush. All rights reserved.  //
/////////////////////////////////////////////////////////
#include <stdio.h>
#include<stdlib.h>
#include"DynamicArray.h"



int main(int argc, char** argv) {
    int k;
DynamicIntArray* ptr = createDAInt(10); 

for(k=0;k<10;k++)
    {       
        setValueAtIndex(k*3,k,ptr);
    }


for(k=0;k<10;k++)
        printf("\n%d",valueAtIndex(k,ptr));
infofunc(ptr);

/////////////////////////////////////////////////////////

for(k=2;k<10;k++)
    {       
       setValueAtIndex(k*2,k,ptr);
    }
    
for(k=0;k<ptr->physicalSize;k++)
        printf("\n%d",valueAtIndex(k,ptr));


infofunc(ptr);
return 0;
}
