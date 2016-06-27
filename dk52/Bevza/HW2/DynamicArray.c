#include "DynamicArray.h"
#include "stdio.h"
#include "stdlib.h" 
DynamicIntArray *createDAInt(int aSize)
{
	DynamicIntArray* anArray=malloc(sizeof(DynamicIntArray)); /*memory for the structure with the array located*/
	anArray->storage = (int*)malloc(aSize*sizeof(int)); /*memory for the array*/
	anArray->physicalSize = aSize;
	anArray->logicalSize = 0; /*there is no elements*/
	
return anArray;
}

void freeDAInt(DynamicIntArray *anArray)
{
	if(anArray!=NULL || anArray->storage!=NULL) /*array isn`t empty*/
        if(anArray->storage!=NULL)
            {
            	free(anArray->storage); /*free the memory of array*/
            	free(anArray);
			}
	else /*if array is empty*/
		return;
}

int valueAtIndex(DynamicIntArray *anArray, int anIndex)
{
	if (anIndex <= 0) 
		{
		printf("Error. Index is less than the array. \n"); /*check the imput value of the index*/
		return -1;
		}
	else if(anIndex > anArray->physicalSize - 1)
			{
			printf("Error. Index is over the array size. \n");
			return -1;
			}
		else
		return anArray->storage[anIndex]; /*return the value at index*/
}

void setValueAtIndex(DynamicIntArray *anArray, int anValue, int anIndex)
{
	if(anIndex>=0)
	{
	int i,*NewStorage;
		if(anIndex<=anArray->physicalSize) /*if index doesn`t extend size of the array*/
		{
			anArray->storage[anIndex]=anValue;
		}
		else if(anIndex>anArray->physicalSize) /*if index extend size of the array, need change it*/
		{
		NewStorage=(int*)calloc(anIndex,sizeof(int)); /*clear allocation of the memory for new array*/
		for(i=0; i<=anArray->physicalSize;i++){ /*replace elements to the new array*/
			NewStorage[i]=anArray->storage[i];
		}
			free(anArray->storage); /*free previous array*/
			anArray->storage=NewStorage; /*new array refers to structure*/
			anArray->storage[anIndex]=anValue; /*insert new element*/
			anArray->logicalSize++;
			anArray->physicalSize=anIndex;
		}
	}
	else
	printf("Error. Index is less than 0.");
	return; /*return new value at the index*/
}
