#include <stdio.h>
int factorial(int fac_input)
{
 int c=1;
 if (fac_input==0)
	 {
		 return 1;
	 }
 else
	 for(fac_input;fac_input>0;fac_input--)
	 {
		 c=c*fac_input;
	 }
	 
	 return c;
}