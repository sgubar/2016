#include "Header.h"


int main(int argc, char *argv[])
{
	int a, b, c; //змінним присвоюємо тип данних типу int
	printf("Enter A\n"); // виводимо повідомлення для вводу А
	scanf_s("%d", &a); // зчитуємо  введені з клавіатури дані та вказуємо на змінну а. %d - десятична ціла типу int
	printf("Enter B\n");
	scanf_s("%d", &b);
	printf("Enter C\n");
	scanf_s("%d", &c);
	double q = f(a, b, c); //тип числа з плаваючою точкою 
	printf("Result: %f\n", q);
	system("pause");
}