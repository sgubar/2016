#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



str * CreateListWithRandomValue(int size, str * inputList) {
	srand ( time(NULL) ); /*Seed*/
	str * StepStore = NULL; /*Create [LISTSIZE] list. Func return point of first element*/
	str * FirstListPointer = NULL; /*Pointer to first element*/
	if (inputList == NULL) {	/*First entry or if inputList is empty (NULL)*/
		str * PointToList = (struct str *)malloc(sizeof(str)); /*Create and allocate memory for new struct*/
		PointToList->value = rand() % 100 - 50; /*Rand value from -50 to 50*/
		PointToList->next = NULL;
		if (size == 1) return PointToList; /*If future list will be have only one element, thent exit and return pointer*/
		StepStore = FirstListPointer = PointToList;  
	}
	for (int i = 1; i < size; i++)
	{
		str * PointList = (str *)malloc(sizeof(str)); /*Another memory allocate for next struct*/
		/*if (StepStore == NULL) {
			PointList->value = rand() % 100 - 50;
			PointList->next = NULL;
			StepStore = PointList = FirstListPointer;
			break;
		};*/
		PointList->value= rand() % 100 - 50;  
		PointList->next = NULL;
		StepStore->next = PointList;
		StepStore = PointList;
	};
	return FirstListPointer;

}

int OutputList(str * InputList) {
	if (InputList == NULL) { printf("\n ERR OUTPUT LIST. POINTER NULL\n"); return -1; }
	if (InputList->next == NULL) { printf("\n LIST ELEMETS: \t %d \n", InputList->value); return  0; };
	printf("\n LIST ELEMETS:\n");
	do
	{
		printf("\t%d", InputList->value);
		InputList = InputList->next;
	} while (InputList != NULL);
	printf("\n\n");
	return 0;
}

int SearchAndDisplayMinMaxElemets(str * InputList) {
	if (InputList == NULL) { printf("\n ERR OUTPUT LIST. POINTER NULL\n"); return -1; }
	if (InputList->next == NULL) { printf("\nList too small for find MIN/MAX value . Requried minimum 2 elemets in list\n"); return  0; };
	int MIN, MAX;
	MIN = MAX = InputList->value;
	InputList = InputList->next;
	printf("\n MIN/MAX elemet:\n");
	do
	{
		if (InputList->value > MAX) MAX = InputList->value;
		if (InputList->value < MIN) MIN = InputList->value;
		InputList = InputList->next;
	} while (InputList != NULL);
	printf("\n\tMAX = %d\tMIN = %d\n\n", MAX, MIN);

	return 0;
}
