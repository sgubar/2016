/* createList.h												*
 *														 	*
 *													 		*
 *															*
 * Created by Sergiy Ninoshvili on 15/06/2016 		        *
 *													        *
 * Copyright © 2016 Sergiy Ninoshvili. All rights reserved. *
 *													        */
#ifndef CREATELIST_H
#define CREATELIST_H
#include "node.h"
#include "List.h"

list *createList()
{
	list *thelist = (list *)malloc(sizeof(list)); //alocate memory for the struct

	//empty list
	thelist->head = thelist->tail = NULL;
	thelist->count = 0;

	return thelist;
}

#endif
