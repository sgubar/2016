#ifndef shellSort_h
#define shellSort_h
#include <stdio.h>

void shellSort (int anArray[], int aCount ) 
{
    int h, i, j, t;
    for (h = aCount; h /= 2;) 
	{
        for (i = h; i < aCount; i++)  // цикл перебираем от текущего h и до конца массива
		{
            t = anArray[i]; // текущий i-й элемент - храним в переменной t
            for (j = i; j >= h && t < anArray[j - h]; j -= h) 
			{
                anArray[j] = anArray[j - h]; // упорядочивание: записываем в j-й элемент j-h-й элемент
            }
            anArray[j] = t; // упорядочивание: записываем в j-й элемент переменную t (текущий i-й элемент)
        }
    }
}
 #endif /* shellSort_h */
int main ()
{
    int a[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1}; // массив
    int n = sizeof a / sizeof a[0]; // размерность массива
    int i;
    for (i = 0; i < n; i++) // для всех элементов массива
        printf("%d%s", a[i], i == n - 1 ? "\n" : " "); // печатать элемент
    shellSort(a, n); // сортировка шелла
    for (i = 0; i < n; i++) // для всех элементов массива
        printf("%d%s", a[i], i == n - 1 ? "\n" : " "); // печатать элемент 
    return 0;
}
