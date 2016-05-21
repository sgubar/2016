//
//  Lab2
// 
//
//  Created by Nazar Bronnikov on 09/05/16.
//  Copyright (C) 2016 Nazar Bronnikov. All rights reserved.
//

#include <stdlib.h>
#include <string.h>

#include "node.h"
 
node_t* node_create (void)
{
	node_t *node_ptr = (node_t *)malloc(sizeof(node_t));
	
	memset(node_ptr, 0, sizeof(node_t));
	
	return node_ptr;
}

node_t* node_create_with_value (int value)
{
	node_t *node_ptr = node_create();
	
	node_ptr->value = value;
	
	return node_ptr;
}

void node_free (node_t *node_ptr)
{
	if (node_ptr != NULL)
	{
		free(node_ptr);
	}
}
