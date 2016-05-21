#include <stdlib.h>
int Module(int A,int B)
{
	int module_output=0;
	
	 if ((2*A) + B != 0)
	 {
		 module_output = 2*A+B;
		 if (module_output < 0)
			 {
				module_output = module_output * (-1);
		 }
      return module_output;
	 }
	 else {
	 printf ("Sorry, you pass incorrect numbers!!! Divizion on zero!!!\n");
	 exit(1);
	 }
	}