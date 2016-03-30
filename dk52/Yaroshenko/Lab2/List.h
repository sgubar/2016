#ifndef List_h
#define List_h

//#include <stdio.h>

typedef struct __str str;

struct __str {
	int value;
	struct str * next;
};

//Create [LISTSIZE] lists and return pointer to firts list
str * CreateListWithRandomValue(int, str *);
//Display list
int OutputList(str *);

int SearchAndDisplayMinMaxElemets(str *);
#endif 
