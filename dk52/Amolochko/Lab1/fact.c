#include <stdio.h>

int fact(int D)
{
 int a=1;
 if (D!=0) 
 { 
	 	 for(D;D>0;D--)
	 {
		 a=a*D;
	 }
	 
	 return a;
}
 else
	return 1;
}
