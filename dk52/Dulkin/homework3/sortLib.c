#include <stdio.h>
#include "list.h"
#include "node.h"

FloatList *Sorting(FloatList *aList)
{
	int sortingIndex = 0;
	int i;
	FloatNode * list = aList->head; // bubble Sort
    FloatNode * node, * node2;
    for( node = list; node; node = node->nextNode )
        for( node2 = list; node2; node2 = node2->nextNode )
        	if( node->value > node2->value ){ 
                i=node->value;
                node->value = node2->value;
                node2->value = i;
            }
	return aList;
}
