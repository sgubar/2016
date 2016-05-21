//
//  Lab2
// 
//
//  Created by Nazar Bronnikov on 09/05/16.
//  Copyright (C) 2016 Nazar Bronnikov. All rights reserved.
//


#ifndef LIST_H_
#define LIST_H_

#include "node.h"

int list_init (void);

node_t* list_add_elem (int value);

int list_del_elem (int key);

int list_swap_maxmin (void);

int list_sort (int opt);

void list_print (void);

int list_get_size (void);


#endif /* LIST_H_ */
