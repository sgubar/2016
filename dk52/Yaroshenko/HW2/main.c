#include <stdio.h>
#include <stdlib.h>
#include "DynamicArray.h"

int main(){
	int size, i,NewIndex, NewValue,IndexToTake,*TakeFromArray;   //size - nachalniy razmer massiva, NewIndex - index novogo elementa, IndexToTake - index nyzhnogo elementa, *TakeFromArray - ykazatel na nyzhniy element massiva
	DynamicIntArray *TheArray;// - ykazatel na stryktyry s massivom
	printf("Enter the size of new array\n");
	scanf("%d",&size);
	
	                             
	TheArray=createDAInt(size);   //sozdaem massiv s proverkoi indexa 
	
	
	
	for(i=0; i<=TheArray->physicalSize;i++){       //vivodim massiv na ekran
	printf("%d ", TheArray->storage[i]);
	}	
	
	printf("What is the index of a new element?");  
	scanf("%d",&NewIndex);
	
	printf("What is the value of a new element?");
	scanf("%d",&NewValue);
	                                 
	setValueAtIndex(TheArray, NewValue, NewIndex);//dobavyaem novuy element v massiv i proveryem ego index	

	
	for(i=0; i<=TheArray->physicalSize;i++){          //vivodim massiv na ekran                            
	printf("%d ", TheArray->storage[i]);
	}
	
	printf("What is the index of element you would like to take from array?");
	scanf("%d",&IndexToTake);
	

	if(IndexToTake>=0 && IndexToTake<=TheArray->physicalSize){                      //sozdaem ykazatel na yacheiky massiva s nyzhnim indeksom (proveryaem index)
		TakeFromArray=valueAtIndex(TheArray, IndexToTake);
		printf("%d",TakeFromArray);
	} else {
	printf("You choose the incorrect index");
	exit(0);		
	}
	
	
	freeDAInt(TheArray);                                //ochishaem pamyat so stryktyroi "DynamicIntArray" i pamayat s massivom
	
	
}
