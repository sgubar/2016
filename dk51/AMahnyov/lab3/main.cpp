#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>
#include "shellSort.h"
#include "SimpleSort.h"

static int *generateArray(int size);
static void printInput(int *input, int size);

int main(){
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, "");
    setviewport(0, 0, getmaxx(), getmaxy(), 0);

    int x = 320, y = 240, radius;
for ( radius = 25; radius <= 125 ; radius = radius + 20)
      circle(x, y, radius);

   system("pause");
   closegraph();
return 0;
}

static int *generateArray(int size){
    srand(time(NULL));
    int *anArray = (int *)malloc(sizeof(int)*size);
    for(int i = 0; i<size; i++){
        *(anArray + i) = rand() %1000;
    }
    return anArray;
}

static void printInput(int *input, int size){
    int i;
		for (i = 0; i < size; i++){
        printf("You gave: [%d] as [%d]\n", i, input[i]);
    }
}
