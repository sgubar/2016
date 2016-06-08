//
//  Lab2
// 
//
//  Created by Nazar Bronnikov on 09/05/16.
//  Copyright (C) 2016 Nazar Bronnikov. All rights reserved.
//

#ifndef NODE_H_
#define NODE_H_

typedef struct _node
{
	int		value;
	
	struct _node	*next_ptr;
} node_t;


node_t* node_create (void);

node_t* node_create_with_value (int value);

void node_free (node_t *node_ptr);

#endif  //NODE_H_
