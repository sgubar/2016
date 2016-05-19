#include <stdio.h>
#include <stdlib.h>
#include "InputFunctions.h"
#include "SingleLinkedNode.h"
#include "SingleLinkedList.h"

#pragma warning(disable : 4996)

void main()
{
	do //Cycle of getting text from file and fool safity
	{
		printf("\tInput text to 'in.txt' and press Enter. \n\tDon't forget add enter symbol to end of text!");
		//getchar();
	} while (!rightText());
	
	//Opening file "in.txt" with reading
	FILE *in;
	in = fopen("in.txt", "r");
	IntList *theList = SLCreateList(); //Creating a list
	IntList *theSortedList = SLCreateList(); //Creating a sorted list
	IntNode *theSwapNode; //Initialize Swap Node
	IntNode *theNode;
	

    //initializing of variables

	char symbol;
	int i = 0;
	int startPosition =	0;
	int length = 0;
	//reading text from file to a[100] by symbol
	while ((symbol = getc(in)) != EOF) //reading file to the end symbol
	{
	
		if (symbol != '\n') //Enter don't take to the list
		{
			theNode = SLCreateNodeWithIntValue(i, symbol);//Creating Node
			SLAddNode(theList, theNode); // Adding Node to the List
			i++; // Counting the length
		}
		else
		{
			length=i;

			for (int index = 0; index < length+startPosition ; index++)
			{
 				theSwapNode = SLCreateNodeWithIntValue(index,SLNodeName(SLNodeAtIndex(theList, length - index  - 1 - startPosition)));
				SLAddNode(theSortedList, theSwapNode);
			}
			i++;
			startPosition++;
		}
		
	}
	
	//initialising the length 
	
	
	puts("\n");

	doPrintSLList(theList);
	
	puts("\n");

	doPrintSLList(theSortedList);

	right(); //Asking the user about correct result of program

	fclose(in); //closing file
	 

	
	
	
	

	


	
	


	getchar();
	system("pause");
	getchar();
	
}

