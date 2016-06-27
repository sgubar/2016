/* changeMaxMin.c (for doubly linked list)					 *
 * finding max and min nodes of the list and swap them		 *
 *															 *
 *															 *
 * Created by Sergiy Ninoshvili on 15/06/2016 		         *
 *													         *
 * Copyright © 2016 Sergiy Ninoshvili. All rights reserved.  *
 *													         */
#include <stdio.h>
#include "List.h"
#include "node.h"

list *changeMaxMin(list *thelist) //BUG max opposite min
{
	node *item = thelist->head;
	node *nextItem = item->next;
	node *min = item;
	node *max = item;

	//finding min and max in the list
	for (; item->next != NULL; nextItem = nextItem->next)
	{
		if (min->data > nextItem->data)
			min = nextItem;

		if (max->data < nextItem->data)
			max = nextItem;

		item = item->next;
	}
	printf("max:%d, min:%d\n", max->data, min->data);

	//creating pointers to around nodes
	node *beforemax = max->previous;
	node *beforemin = min->previous;
	node *aftermax = max->next;
	node *aftermin = min->next;

	if (max->next == min || min->next == max) //watching for opposite location of max and min
	{
		//                       max         min
		//4			5   		 10	  	     1		    6		  7   - imagine that it is our list  
		// beforemax^    beforemin^	 aftermax^	aftermin^							or
		//                       min         max							
		//4			5   		  1	  	     10		    6		  7     
		// beforemin^    beforemax^	 aftermin^	aftermax^
		//
		min->previous = (aftermax == min)? beforemax : max; 
		min->next = (aftermax == min) ? max : aftermax;

		max->next = (aftermax == min) ? aftermin : min;
		max->previous = (aftermax == min)? min : beforemin;

		if (aftermin != NULL)
			aftermin->previous = (aftermax == min)? max : beforemin;
		else thelist->tail = max;

		if (beforemax != NULL)
			beforemax->next = (aftermax == min)? min : aftermax;
		else thelist->head = min;

		if (beforemin != NULL)
			beforemin->next = (aftermax == min)? aftermin : max;
		else thelist->head = max;

		if (aftermax != NULL)
			aftermax->previous = (aftermax == min)? beforemax : min;
		else thelist->tail = min;

		return thelist;
	}

		if (beforemax != NULL && beforemax != min) //max is not a head of the list
			beforemax->next = min;
		else thelist->head = min; //if max head of the list swap to min head of the list

		if(aftermax != NULL && aftermax != min) //max is not a tali of the list
		    aftermax->previous = min; 
		else thelist->tail = min; //if max tail of the list swap to min tail of the list

		if (beforemin != NULL && beforemin != max) //min is not a head of the list
			beforemin->next = max;
		else thelist->head = max; //if min head of the list swap to max head of the list

		if(aftermin != NULL && aftermin != max) //min is not a tail of the list
			aftermin->previous = max;
		else thelist->tail = max; //if min tail of the list swap to max tail of the list
		
		min->next = aftermax;
		min->previous = beforemax;
	
		max->next = aftermin;
		max->previous = beforemin;

	return thelist;
}