#include <stdio.h>
#include <stdlib.h>
#include "getInput.h"

int *getInput(int argNum){
//    int answer[argNum]; <! -- it is local variable, so it will be dead after go out from this function
	
	//The great solution is
	int *answer = (int *)malloc(sizeof(int) * argNum);
	
	if (NULL != answer)
	{
		 for(int i = 0; i < argNum; i++)
		 {
			  printf("Write an argument [%d]: ", i);
			//answer is pointer, so you can navigate through memory by use corresponding offset
			//(answer + offset)
			// so (answer + 0) is the same as (&answer[0])
			// (anser + 1) == (&answer[1])
			  scanf("%d", (answer + i));
		 }
	}
	
	return answer;
}
