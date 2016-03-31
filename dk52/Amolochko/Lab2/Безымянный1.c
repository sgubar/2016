#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <list>


//создаем функцию для вывода списка
void Print(mylist *b)
{
    mylist *print = b;
    while(print)
    {
        printf('%d', print->a.key, "->");
        print = print->next;
    }
    printf("NULL\n");
}


//функция заполнения и сортировки
  int main()
  {
      //заполнение
  srand(time(0));
    int n, tmp;
    int *begin, *end;//указатель на начало и конец списка
    list<int> mylist; //создаем список
      for (int i = 0; i < 10; i++)
      {
          scanf("%d", &n);

          //заполняем список значениями от 1 до 10 включительно
          mylist.push_back(n);
      }
        int k = 0;
        for int i= 0; i<10; i++)
        {
            if(mylist->begin < mylist->next) k=i+1;
        }
      //сортировка
       for (int i = 0; i <k ; i++)
      {
          for (int j = 0; j < k; j++)
          {
              if(mylist->begin < mylist->next)//если последующий больше предыдущего

                  //меняем местами элементы упорядочивая по убыванию
              {
                tmp = mylist->next;
                mylist->begin = mylist->next;
                mylist->begin =tmp;
              }
          }
      }

      printf("Вывод списка");

      Print(begin);
      _getch();
      return 0;
  }
