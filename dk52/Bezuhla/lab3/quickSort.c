#ifndef quickSort_h
#define quickSort_h
#include <stdio.h>
 
void quickSort (int anArray[], int aCount)
{
    int i, j, p, t;
    if (aCount < 2) 
        return; 

    p = anArray[aCount / 2]; // элемент из середины массива
    for (i = 0, j = aCount - 1;; i++, j--) 
	{
        while (anArray[i] < p) // пока i-й элемент меньше p - элемента из середины
            i++; // инкрементируем i
        while (p < anArray[j]) // пока j-й элемент больше p - элемента из середины
            j--; // декрементируем j
        if (i >= j) // если i и j пересеклись 
            break; // выход из цикла
        t = anArray[i]; 
        anArray[i] = anArray[j];
        anArray[j] = t;
    }
    quickSort(anArray, i); // вызиваем рекурсивно quickSort для левой половины
    quickSort(anArray + i, aCount - i); // вызиваем рекурсивно quickSort для правой половины
}
#endif /* quickSort_h */
 
int main ()
{
	int a[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1}; // массив
    int n = sizeof a / sizeof a[0]; // размерность массива
    int i;
    for (i = 0; i < n; i++)//для всех элементов массива
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");// печатать элемент
    quickSort(a, n);// быстрая сортировка 
    for (i = 0; i < n; i++)// для всех элементов массива
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");// печатать элемент
    return 0;
}
