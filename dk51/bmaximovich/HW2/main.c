//
//  main.c
//
//
//  Created by Bogdan Maximovich on 15/05/16.
//  Copyright © 2016 Bogdan Maximovich. All rights reserved.
//
#include <stdlib.h>
#include<stdio.h>

//перевыделение памяти
int* my_realloc(int*, size_t, size_t);

int main()
{
   int *arr = (int*) malloc(10 * sizeof(int));

    for (size_t i = 0; i < 10; ++i)
        arr[i] = i;

    for (size_t i = 0; i < 10; ++i)
    printf("%d ", arr[i]);
        printf("\n");

    arr = my_realloc(arr, 10, 15);

    for (size_t i = 10; i < 15; ++i)
        arr[i] = i;

    for (size_t i = 0; i < 15; ++i)
        printf("%d ", arr[i]);
        printf("\n");

    free(arr);

	system("pause");
}

int* my_realloc(int* array, size_t size,size_t newSize)
{
    int *NewArr = (int*) malloc(newSize * sizeof(int));

  if(size<=newSize){
        for (size_t i = 0; i < size; ++i)
    {
     NewArr[i] = array[i];
    }
    for (size_t i = size; i < newSize; ++i)
    {
     NewArr[i] = 0;
    }
  }
  else{
    for (size_t i = 0; i < newSize; ++i)
    {
     NewArr[i] = array[i];
    }
  }
    free(array);
    return NewArr;
}

