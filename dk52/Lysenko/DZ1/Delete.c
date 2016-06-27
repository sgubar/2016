#include <stdio.h>
#include <stdlib.h>
#include "CreateNode.h"
#include "Delete.h"

Node *DeleteNode(Node *head, int m) {
	int i = 1;
	Node *prev, *removed, *succesive, *read;
	prev = head;

	if (m == 1) {                          //udalyaem perviy elemen v spiske
		removed = prev;
		head = prev->next;
	}
	else {

		for (i; i<m - 1; i++) {                //nahodim nodu, kotoraya dolzna nahoditsya pered udalyaemoi
			prev = prev->next;
		};
		removed = prev->next;            //razrivaem svyazi mezhdu udalennoy nodoy
		succesive = removed->next;
		prev->next = succesive;
		removed->next = NULL;
	};
	read = head;						//vivodim spisok na ekran
	for (i = 1; read != NULL; i++) {
		printf("[%d]:%d ", i, read->number);
		read = read->next;
	};
	return removed;
}
