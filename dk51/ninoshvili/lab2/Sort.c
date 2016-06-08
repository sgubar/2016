#include<stdio.h>
#include<stdlib.h>
#include"node.h"
#include"Sort.h"

node *Sort(node *head)
{
		int index, j;

		for (index = 0; index < 10; index++)
		{
			node *previousItem = head; //pointer to the first element
			node *firstItem = previousItem->next; //to the second
			node *secondItem = firstItem->next; // to the third

			for (j = 0; j<10; j++)
			{
				if (previousItem == head && previousItem->data > firstItem->data)
				{
					head = firstItem; //second element become the first
					firstItem->next = previousItem; //first element has adress of the element with lower data
					previousItem->next = secondItem; //element with lower data has adress of the third element
					previousItem = firstItem; // to save the sequence change pointers
					firstItem = previousItem->next;
					secondItem = firstItem->next;
				}

				
				if (secondItem == NULL) //wathcing for the end of the list
					break;

				if (firstItem->data > secondItem->data)
				{
					firstItem->next = secondItem->next;
					previousItem->next = secondItem;
					secondItem->next = firstItem;
					firstItem = previousItem->next;
					secondItem = firstItem->next;
				}
				
				previousItem = previousItem->next;//go father in the list
				firstItem = firstItem->next;
				secondItem = secondItem->next;
			}
			
		}
		return head;
}