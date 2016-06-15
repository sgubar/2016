/* List.h													*
 *  														*
 *												 			*
 *															*
 * Created by Sergiy Ninoshvili on 15/06/2016 		        *
 *													        *
 * Copyright © 2016 Sergiy Ninoshvili. All rights reserved. *
 *													        */
#ifndef LIST_H
#define LIST_H
#include <stdlib.h>
#include "node.h"

typedef struct {
    struct node *head;
    struct node *tail;
	int count;
}list;

#endif
