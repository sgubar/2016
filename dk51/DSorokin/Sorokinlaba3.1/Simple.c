#include "Simple.h"

void bubbleSort(int anArray[], int aSize)
{
	for (int theOut = aSize - 1; theOut > 1; theOut--)//Обираэмо  межу сортування 
	{
		for (int theIn = 0; theIn < theOut; theIn++)//йдемо до обраної межі
		{
			if (anArray[theIn] > anArray[theIn + 1])//якщо єлемент більше наступного, то поміняти їх місцями
			{
				int theTmp = anArray[theIn];
				anArray[theIn] = anArray[theIn + 1];
				anArray[theIn + 1] = theTmp;
			}
		}
	}
}

void selectionSort(int anArray[], int aSize)
{
	for (int theOut = 0; theOut < aSize - 1; theOut++)//перебираємо масив
	{
		int theMinIndex = theOut;//обираємо ключь порівняння як перший єлемент

		for (int theIn = theOut + 1; theIn < aSize; theIn++)//йдемо по масиву порівнюючи кожний єлемент з ключем 
		{
			if (anArray[theIn] < anArray[theMinIndex])//якщо єлемент меньше ключе, то він стає новим ключем
			{
				theMinIndex = theIn;//знаходимо мінімальний
			}
		}

		int theTmp = anArray[theOut];//виконуємо перестановку
		anArray[theOut] = anArray[theMinIndex];
		anArray[theMinIndex] = theTmp;
	}
}

void insertionSort(int anArray[], int aSize)
{
	for (int theOut = 1; theOut < aSize; theOut++)
	{
		int theTmp = anArray[theOut];
		int theIn = theOut;

		while (theIn > 0 && anArray[theIn - 1] >= theTmp)
		{
			anArray[theIn] = anArray[theIn - 1];
			--theIn;
		}

		anArray[theIn] = theTmp;
	}
}

