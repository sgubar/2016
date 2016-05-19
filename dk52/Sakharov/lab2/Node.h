

/* 
 * File:   Node.h
 * Author: Dmitry Sakharov
 *
 * Created on 10 квітня 2016, 2:47
 */

#ifndef NODE_H
#define NODE_H
#include <stdio.h>

#include<stdlib.h>
typedef struct Node Node;
struct Node
{
    int value;
    Node* nextptr;//pointer on next node
};

Node* CreateNode(int value);

void SLFreeNode(Node *aNode);

#endif


