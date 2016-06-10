#ifndef NODE_H
#define NODE_H

typedef struct {
	int data;
	struct node *next;
    struct node *previous;
}node;

node *createNode(int value);

#endif
