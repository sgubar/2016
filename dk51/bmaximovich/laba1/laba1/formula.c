
#include "Header.h"

int fac(int n) {   //�������� ����� n
	int k = 1;  
	for (int i = 1; i <= n; i++) //���� � ���� ����� ��� ���������� n ���������� �����, � ���������� �� 1
		k *= i; //���� � ����� n ���������� �� �����
	return k;
}

double f(int a, int b, int c) {
	double q = 0;
	q += (double)(a*b) / (b + c*c);
	for (int i = 0; i <= b; i++) q += fac(i); //�� ����� ���������� ����� �� q �������� �������� ��� ������� ������� fac
	return q;
}