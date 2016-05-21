//
//  Lab2
// 
//
//  Created by Nazar Bronnikov on 09/05/16.
//  Copyright (C) 2016 Nazar Bronnikov. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "list.h"


void show_menu (int *choise);
void generate_list (int list_size);

int main(void)
{
	list_init();
	
	int choise = -1;
	int exit_val = 1;
	
    while (exit_val) 
    {
		show_menu(&choise);
		
		printf("\n");

		switch (choise)
		{
			case 0:
			{
				int size = 0;

				printf("Razmer spiska:  ");

				scanf_s("%d%*[^\n] ", &size);

				generate_list(size);

				list_print();

				printf("\n \n \n");
			}
			break;
			
			case 1:
			case 2:
			{
				if (list_sort(choise))
				{
					printf("\n \n Oshibka pri sortirovke. \n \n");
					
					break;
				}
				
				list_print();
				
				printf("\n \n \n");
			}
			break;
			
			case 3:
			{
				if (list_swap_maxmin())
				{
					printf("\n \n V spiske odin element \n \n");
					
					break;
				}
				
				list_print();
				
				printf("\n \n \n");
				
			}
			break;

			case 4:
			{
				printf(" \n Vvedite klyuch:  ");
				
				int key = 0;
				
				scanf_s("%d%*[^\n] ", &key);
				
				int res = list_del_elem(key);

				if (res == 0)
				{
					list_print();
				}
				if (res == 1)
				{
					printf("Klyuch ne nayden \n");
				}
				else if (res == 2)
				{
					printf("Spisok pustoy \n");

					break;
				}
				
				printf("\n \n \n");
			}
			break;

			case 5:
			{
				// todo manual adding elements to the list
				
				list_print();
				
				printf("\n \n \n");
				
				while (list_get_size() >= 3)
				{
					list_del_elem(3);
					
					list_print();
					
					printf("\n \n \n");
				}
			}
			break;
			
			case 9:
			{
				exit_val = 0;
			}
			break;
			
			default:
			{
				printf("Nevernaya komanda \n");
			}
			break;
		}
    }
	
	return 0;
}

void show_menu (int *choise)
{
	printf("Vvedite nomer komandu: \n");
	
	printf("\t Generatciya spiska - 0. \n");
	
	printf("\t Sortirovka po vozrostaniy - 1. \n");
	printf("\t Sortirovka po spadaniy - 2. \n");
	
	printf("\t Pomenyat mestami max i min elementu - 3. \n");
	
	printf("\t Udalit element po klyuchu - 4. \n");
	
	printf("\t Udalit kazhduy 3y element - 5. \n");
	
	printf("\t Vuhod is programmu - 9. \n");
	
	printf("\n Vash vubor: ");

	scanf_s("%d%*[^\n] ", choise);
}

void generate_list (int list_size)
{
	srand((unsigned int)time(NULL));
	
	int value = 0;
	
	printf("\n");

	list_init();

	for (int i = 0; i < list_size; i++)
	{
		value = rand() % 1000;
		
		if (list_add_elem(value) == NULL)
		{
			break;
		}
	}
}
