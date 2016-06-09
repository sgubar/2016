/* 
 * File:   Node.h
 * Author: Ruslan Kucherenko
 *
 * Created on 1 червня 2016, 1:21
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


