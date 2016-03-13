#include <stdio.h>
#include <stdlib.h>
#include "getInput.h"

//static void printInput(int *input);
static void printInput(int *input, int size); // you should use additional parameter that describes the size of array or use special symbol to mark the end of array - the same as in a string (char *)

int main(){
    int argNum = 0;
    printf("How many arguments do you want?\n");
    scanf("%d", &argNum);

    int *recievedAnswer = NULL;

    recievedAnswer = getInput(argNum);

	 if (NULL != recievedAnswer)
	 {
	    printInput(recievedAnswer, argNum);
	 
		 //to avoid memory leak you should free memory
		 free(recievedAnswer);
	 }

    return 0;
}

void printInput(int *input, int size){
    int i;
// There are the bad solution, because you calculate the size of pointer nor the size of array (size of memory block)
//    for(i = 0; i<sizeof(input); i++){
		for (i = 0; i < size; i++){
        printf("You gave: [%d] as [%d]\n", i, input[i]);
    }
}
