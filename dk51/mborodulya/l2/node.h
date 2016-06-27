//
//  node.h
//  linked list
//
//  Created by Masha Borodulya
//  Copyright © 2016 Masha Borodulya. All rights reserved.
//

#ifndef node_h
#define node_h

#include <stdio.h>

struct FloatNode {
    float value;
    FloatNode *nextNode;
};



FloatNode *CreateFloatNode(float newValue);
void FreeNode(FloatNode *tmp);


#endif

