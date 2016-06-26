#include <stdio.h>
#include <stdlib.h>

#include "createList.h"
#include "reverseList.h"
#include "writelist.h"


int main() {
	List* list = NULL;
	
	for (int i = 0; i < 20; ++i) 
	{
		push(&list, ((i + 5) % 10) + 1);
	}
	
	printf("You have list of 20 numbers:\n");
	write(list);

	printf("\nTransformed list:\n");
	write(reverseBetween(list, 10));


	system("pause");
	return 0;
}
