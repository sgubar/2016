#include <stdio.h>
int main (){
	char name[256];
	printf("Hello! What's your name? ");
	scanf("%s",&name);
	printf("It's nice to meet you, %s! And my name is Dima.", name);
}
