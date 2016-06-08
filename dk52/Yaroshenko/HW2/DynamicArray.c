//
//  DynamicArray.c
//  doTest
//
//  Created by Slava Gubar on 3/24/16.
//  Copyright © 2016 Slava Gubar. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "DynamicArray.h"

DynamicIntArray *createDAInt(int aSize){
	if(aSize>0){
	DynamicIntArray *TheArray=malloc(sizeof(DynamicIntArray)); //vidilyaem pamyat pod stryktyry s massivom

	TheArray->storage=(int*)calloc(aSize,sizeof(int));         //vidilyaem pamyat pod massiv i obnylyaem ego elementi

	TheArray->logicalSize=0;
	TheArray->physicalSize=aSize-1;
	return TheArray;
	}else{
	printf("You choose the incorrect index");
	exit(0);
	}
		
	}
	
	

void setValueAtIndex(DynamicIntArray *anArray, int anValue, int anIndex){
	if(anIndex>=0){     
	int NewIndex=anIndex, value=anValue,i,*NewStorage;
	DynamicIntArray *TheArray=anArray;
	
	if(NewIndex<=TheArray->physicalSize){                  //vstavlyaem element v slychae esli ne nyzhno izmenyat razmer massiva 
		TheArray->storage[NewIndex]=value;
	}
	
	
	if(NewIndex>TheArray->physicalSize){                   //vstavlyaem element v slychae esli nyzhno izmenyat razmer massiva 
		NewStorage=(int*)calloc(NewIndex,sizeof(int));     //vidilyaem pamyat pod novuy massiv i obnylyaem ego elementi
		for(i=0; i<=TheArray->physicalSize;i++){           //perenosim elementi so starogo massiva v novuy
			NewStorage[i]=TheArray->storage[i];
		}
			free(TheArray->storage);                       //ydalyaem staruy massiv
			TheArray->storage=NewStorage;                  //"privyazivaem" noviy massiv k stryktyre DynamicIntArray
			TheArray->storage[NewIndex]=value;             //vstavlyem noviy element
			TheArray->logicalSize++;
			TheArray->physicalSize=NewIndex;
		}
	}else{
	printf("You choose the incorrect index");
	exit(0);
	}
}
	
int valueAtIndex(DynamicIntArray *anArray, int anIndex){   //sozdaem ykazatel na yacheiky massiva s nyzhnim indeksom (proveryaem index)
	DynamicIntArray *TheArray=anArray;
	
	int i=anIndex, *TakeFromArray;
	return TakeFromArray=TheArray->storage[i];
}


void freeDAInt(DynamicIntArray *anArray){          
	DynamicIntArray *TheArray=anArray;
	free(TheArray->storage);                               //"chistim" massiv
	free(TheArray);                                        //"chistim" stryktyry
}





