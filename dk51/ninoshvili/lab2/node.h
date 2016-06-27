/* node.h													*
 *  														*
 *													 		*
 *															*
 * Created by Sergiy Ninoshvili on 15/06/2016 		        *
 *													        *
 * Copyright © 2016 Sergiy Ninoshvili. All rights reserved. *
 *													        */
#ifndef NODE_H
#define NODE_H

typedef struct {
	int data;
	struct node *next;
    struct node *previous;
}node;

node *createNode(int value);

#endif
