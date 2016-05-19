#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include "stdafx.h"

void menu(); 	// Меню.
int get_count();	// Запрос на кол-во генерируемых элементов.

// Простые функции сортировки.
void sort_bubble(int *array, int size);	// Пузырьком
void sort_insert(int *array, int size);	// Вставками
void sort_selection(int *array, int size);	// Выбором

// Более сложные.
void sort_quick(int *array, int size);	// Быстрая
void sort_shell(int *array, int size);	// Алгоритм Шелла

// Заполнение.
void full_array(int *array, int size);

// Вывод.
void show_array(const int *array, int size);

// Получение опорного элемента для быстрой сортировки.
double get_pivot_median(int *array, int size);

// Таймер.
void timer();

int main () {
	// Главный цикл, выход обеспечен внутри.
	while(1) {
		menu();
	}
}


void menu() {
	// Получаем значение количества элементов
	int count = get_count();

	int *array = (int *)calloc(count, sizeof(int));
	full_array(array, count);

	printf("Array generated with %d elements;\n", count);
	show_array(array, count);
	char choice[5];

	// Непосредственно, меню.
	while(1) {
		int* current_array = (int *)calloc(count, sizeof(int));
		memcpy(current_array, array, count * sizeof(int));

		printf("\nMenu:\n");
		printf("1) Bubble sort\n");
		printf("2) Selection sort\n");
		printf("3) Insertion sort\n");
		printf("4) Quick sort\n");
		printf("5) Shell sort\n");

		printf("6) New array\n");
		printf("7) Exit\n>>> ");

		scanf("%s", choice);
		//printf("\nChoice: %c", choice);

		// Таймер имеет статическую переменную, которая обозначает 2 состояния, указывая на то, 
		// засекать время или выводить. 
		switch(choice[0]) {
			case '1' : { timer(); sort_bubble(current_array, count); show_array(current_array, count); timer(); break; }
			case '2' : { timer(); sort_selection(current_array, count); show_array(current_array, count); timer(); break; }
			case '3' : { timer(); sort_insert(current_array, count); show_array(current_array, count); timer(); break; }
			case '4' : { timer(); sort_quick(current_array, count); show_array(current_array, count); timer(); break; }
			case '5' : { timer(); sort_shell(current_array, count); show_array(current_array, count); timer(); break; }

			case '6' : { return; }
			case '7' : { exit(0); break; }
			default: { printf("Incorrect.\n"); break;}
		}

		current_array = array;
	}

}

// Простые функции сортировки.

void sort_bubble(int *array, int size) {
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size - i - 1; j++) {
			if( array[j] > array[j + 1] ) {
				array[j] ^= (array[j + 1] ^= (array[j] ^= array[j + 1]));
			}
		}
	}
}
void sort_insert(int *array, int size) {
	int key;
	int i;
	for(int j = 1; j <  size; j++){  
    	key = array[j];
    	i = j - 1;
    	while( (i >= 0) && (array[i] > key)){
         	array[i+1] = array[i];
        	i--;
    	}
    	array[i+1] = key;
	}
}

void sort_selection(int *array, int size) {
	for (int idx_i = 0; idx_i < size - 1; idx_i++)
    {
        int min_idx = idx_i;
        for (int idx_j = idx_i + 1; idx_j < size; idx_j++)
        {
            if (array[idx_j] < array[min_idx])
            {
                min_idx = idx_j;
            }
        }

        if (min_idx != idx_i)
        {
            array[idx_i] ^= ( array[min_idx] ^= (array[idx_i] ^= array[min_idx]));
        }
    }
}

// Более сложные.
void sort_quick(int *array, int size) {
	if( size < 2)
		return;

	double pivot = get_pivot_median(array, size);

	int count_left = 0, count_right = 0;
	int* left = (int *)calloc(size, sizeof(int));
	int* right = (int *)calloc(size, sizeof(int));

	for(int i = 0; i < size; i++) {
		if( array[i] > pivot ) { right[count_right] = array[i]; count_right++; }
		else { left[count_left] = array[i]; count_left++; }
	}

	sort_quick(left, count_left);
	sort_quick(right, count_right);



	for(int i = 0; i < count_left; i++) {
		array[i] = left[i];
	}
	for(int i = 0; i < count_right; i++) {
		array[i + count_left] = right[i];
	}
}
void sort_shell(int *array, int size) {
	unsigned i, j, k;
	int t;
	for(k = size/2; k > 0; k /=2)
        for(i = k; i < size; i+=1)
        {
            t = array[i];
            for(j = i; j>=k; j-=k)
            {
                if(t < array[j-k])
                    array[j] = array[j-k];
                else
                    break;
            }
            array[j] = t;
        }
}

// Заполнение.
void full_array(int *array, int count) {
	srand(time(NULL));
	const int randMin = 0;
	const int randMax = 10000;

	for(int i = 0; i < count; i++) {
		array[i] = (rand() % (randMax - randMin) + randMin);
	}
}

double get_pivot_median(int *array, int size) {
	return ( array[0] + array[size / 2] + array[size - 1] ) / 3;
}

void timer() {
	static int start = -1;
	if(start == -1){
		// Таймер был зброшен или ещё не засекался.
		start = clock();
		printf("\n Clock started\n");
	}
	else {
		// Если время установлено (не -1),
		// 	то выводим разницу.
		start = clock() - start;
		printf("\n Elapsed: %d ms.\n", start);
		start = -1;
	}
}


void show_array(const int *array, int size) {
	printf("\nArray: \n");
	for(int i = 0 ;i < size; i++) {
		printf("%d  ", array[i]);
	}
	printf("\n");
}

int get_count() {
	printf("Enter count of elements in array(n >= 0 and n <= 10000): ");
	int count;
	scanf("%d", &count);
	if(count < 0)
		count = -count;

	return count;
}
