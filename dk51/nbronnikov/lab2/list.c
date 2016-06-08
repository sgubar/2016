//
//  Lab2
// 
//
//  Created by Nazar Bronnikov on 09/05/16.
//  Copyright (C) 2016 Nazar Bronnikov. All rights reserved.
//

#include <string.h>
#include <stdio.h>

#include "list.h"

#include "node.h"


typedef struct
{
	node_t	*head_ptr;
	node_t	*tail_ptr;
	
	int		size;
} list_t;


static list_t ring_list;


node_t* list_find_maxmin (int opt);

node_t* list_find_elem (int key, int *value_ptr);

node_t* list_find_prev_cell (node_t *cell_ptr);



int list_init (void)
{
	memset(&ring_list, 0, sizeof(list_t));
	
	return 0;	
}


node_t* list_add_elem (int value)
{

	node_t *node_ptr = node_create_with_value(value);
	
	if (node_ptr == NULL)
	{
		return NULL;
	}

	if (ring_list.head_ptr == NULL && ring_list.tail_ptr == NULL)
	{
		ring_list.head_ptr = node_ptr;
		ring_list.tail_ptr = ring_list.head_ptr;
		
	}
	else
	{
		ring_list.tail_ptr->next_ptr = node_ptr;

		ring_list.tail_ptr = ring_list.tail_ptr->next_ptr;
		ring_list.tail_ptr->next_ptr = ring_list.head_ptr;
	}
	
	ring_list.size++;
	
	return ring_list.tail_ptr;
}

int list_del_elem (int key)
{
	if (key > ring_list.size)
	{
		return 1;
	}

	node_t *next_node = NULL;

	for (int i = 0; i < key - 1; i++)
	{
		if (next_node == NULL)
		{
			next_node = ring_list.head_ptr;
		}
		else
		{
			next_node = next_node->next_ptr;
		}
	}
	
	if (ring_list.head_ptr == ring_list.tail_ptr)
	{
		list_init();

		return 2;
	}
	
	if (key == 0)
	{
		node_t *temp_ptr = ring_list.head_ptr;

		ring_list.head_ptr = ring_list.head_ptr->next_ptr;
		ring_list.tail_ptr->next_ptr = ring_list.head_ptr;

		node_free(temp_ptr);

		ring_list.size--;
	}
	else
	{
		node_t *temp_ptr = next_node->next_ptr;
		next_node->next_ptr = next_node->next_ptr->next_ptr;
		
		if (temp_ptr == ring_list.tail_ptr)
		{
			ring_list.tail_ptr = next_node;
		}

		node_free(temp_ptr);

		ring_list.size--;
	}
	
	return 0;
}

int list_swap_maxmin (void)
{
	node_t *max_ptr = list_find_maxmin(1);
	node_t *min_ptr = list_find_maxmin(0);
	
	if (min_ptr == NULL || max_ptr == NULL)
	{
		return 1;
	}
	else if (max_ptr == min_ptr)
	{
		return 2;
	}
	
	node_t temp_cell;
	
	memcpy(&temp_cell, max_ptr, sizeof(node_t));
	
	max_ptr->value = min_ptr->value;
	min_ptr->value = temp_cell.value;
	
	return 0;
}

int list_sort (int opt)
{
	node_t *next2_ptr = ring_list.head_ptr;
	
	node_t temp_cell;
	
	int swapped = 0;
	int end1_flag = 0;
	int end2_flag = 0;
	
	for (int i = 0; i < ring_list.size - 1; i++)
	{
		for (int j = 0; j < ring_list.size - 1; j++)
		{
			switch (opt)
			{
				case 1:		// by value from min
				{
					if (next2_ptr->value > next2_ptr->next_ptr->value)
					{
						memcpy(&temp_cell, next2_ptr, sizeof(node_t));
						
						next2_ptr->value = next2_ptr->next_ptr->value;
						next2_ptr->next_ptr->value = temp_cell.value;
						
						swapped = 1;
					}
				}
				break;
				
				case 2:		// by value from max
				{
					if (next2_ptr->value < next2_ptr->next_ptr->value)
					{
						memcpy(&temp_cell, next2_ptr, sizeof(node_t));
						
						next2_ptr->value = next2_ptr->next_ptr->value;
						next2_ptr->next_ptr->value = temp_cell.value;
						
						swapped = 1;
					}
				}
				break;
				
				default:
				{
					return 1;
				}
				break;
			}
			
			next2_ptr = next2_ptr->next_ptr;
		}
		
		next2_ptr = ring_list.head_ptr;

		if(!swapped)
		{
			break;
		}
		else
		{
			swapped = 0;
		}
	}
	
	return 0;
}

void list_print (void)
{
	node_t *next_ptr = ring_list.head_ptr;
	
	for (int i = 0; i < ring_list.size; i++)
	{
		printf("%d.:\t %d \n", i, next_ptr->value);
		
		next_ptr = next_ptr->next_ptr;
	}
}


int list_get_size (void)
{
	return ring_list.size;
}


node_t* list_find_maxmin (int opt)
{
	node_t *next_ptr = ring_list.head_ptr;
	node_t *sought_cell_ptr = next_ptr;
	
	
	for (int i = 0; i < ring_list.size; i++)
	{
		switch (opt)
		{
			case 0:		// min val
				if (next_ptr->value < sought_cell_ptr->value)
				{
					sought_cell_ptr = next_ptr;
				}
			break;
			
			case 1:		// max val
				if (next_ptr->value > sought_cell_ptr->value)
				{
					sought_cell_ptr = next_ptr;
				}
			break;
			
			default:
				return NULL;
		}
		
		next_ptr = next_ptr->next_ptr;
	}
	
	return sought_cell_ptr;
}

#if 0

node_t* list_find_elem (int key, int *value_ptr)
{
	node_t *next_ptr = ring_list.head_ptr;
	
	for (int i = 0; i < ring_list.size; i++)
	{
		if (key == i)
		{
			if (value_ptr != NULL)
			{
				*value_ptr = next_ptr->value;
			}
			
			return next_ptr;
		}

		next_ptr = next_ptr->next_ptr;
	}
	
	return NULL;
}

node_t* list_find_prev_cell (node_t *cell_ptr)
{
	node_t *next_ptr = ring_list.head_ptr;
	
	for (int i = 0; i < ring_list.size; i++)
	{
		if (next_ptr->next_ptr == cell_ptr)
		{
			return next_ptr;
		}

		next_ptr = next_ptr->next_ptr;
	}
	
	return NULL;
}

#endif
