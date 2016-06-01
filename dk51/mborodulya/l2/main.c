
//  main.c
//  linked list
//
//  Created by Masha Borodulya
//  Copyright © 2016 Masha Borodulya. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "list.h"


int main()
{
    FloatNode *myNode0, *myNode1, *myNode2, *myNode3, *myNode4, *myNode5, *myNode6, *myNode7, *myNodeToInsert;
    printf("%f\n", myNode5->value);

    int count;
    myNode0 = CreateFloatNode(0.6);
    myNode1 = CreateFloatNode(0.9);
    myNode2 = CreateFloatNode(1.66);
    myNode3 = CreateFloatNode(0.06);
    myNode4 = CreateFloatNode(0.3);
    myNode5 = CreateFloatNode(10.01);
    myNode6 = CreateFloatNode(2.01);
    myNode7 = CreateFloatNode(16.01);

    FloatList *list = CreateFloatList();
    AddNodeToList(list, myNode0);
    AddNodeToList(list, myNode1);
    AddNodeToList(list, myNode2);
    AddNodeToList(list, myNode3);
    AddNodeToList(list, myNode4);
    AddNodeToList(list, myNode5);
    AddNodeToList(list, myNode6);
    AddNodeToList(list, myNode7);

    PrintList(list);

    printf("%3d\n",CountList(list));

    for(int i = 0; i < CountList(list); i++)
    {
        printf("item %f\n", getNodeAtIndex(list,i)->value);
    }

    printf("tests swap\n");
    SwapFloatNodes(list, 0, 1);
    PrintList(list);
    SwapFloatNodes(list, 2, 3);
    PrintList(list);

    printf("tests changeminandmax\n");
    PrintList(ChangeMinMaxElements(list));

    SelectionSort(list);
    PrintList(list);

    BubbleSort(list);
    PrintList(list);

    return 0;
}
