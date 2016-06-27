#include <stdio.h>
#include <stdlib.h>

struct node //структура дерева
{
  int data; //значение
  struct node * left; //левая ветка
  struct node * right; //правая ветка
};

struct tree //структура дерева
{
  struct node * root;	
  int count;			// число узлов 
};

struct tree * tree_create()  
{ 
	struct tree * new_tree = malloc(sizeof * new_tree); 
	if (new_tree == NULL) return NULL; 
	new_tree->root = NULL; 
	new_tree->count = 0;
	return new_tree; 
}

int insert(struct tree * search_tree, int item) //функция добавления узла в дерево
{ 
	struct node * search_node, **new_node;
	//объявляем search_node - указатель на ноду в new_node - указатель на указатель на ноду

	new_node = &search_tree->root; //в new_node записываем корень полученного на вход дерева.
	search_node = search_tree->root; 
	//в search_node тоже записывем корень полученного на вход функции дерева.

	for(;;) 
	
	{
		if(search_node == NULL) // если search_node - NULL
		{
			search_node = *new_node = malloc(sizeof * search_node); 
			// присваиваем search_node new_node и выделяем память
			if(search_node != NULL) // если search_node - не NULL
			{
				search_node->data = item; // записываем элемент который надо было вставить в search_node
				search_node->left = search_node->right=NULL; 
				//а для левого и правого листа свежодобавленой ноды записываем NULL
				search_tree->count++; // указываем, что с добавлением ноды число нод в дереве стало больше на еденицу
				return 1; // выходим из функции и возвращаем 1, потому что все успешно вставилось.
			}
			else return 0; // выходим из функции и возвращаем 0 - при вставке произошла ошибка. 
			
		}
		else if(item == search_node->data) return 2; // если search_node - не NULL и элемент, 
		// который мы хотим вставить уже есть в дереве - то мы выходим из функции и возвращаем 2 - потому что такой элемент уже есть
		else if(item > search_node->data) // если search_node - не NULL и элемент, который мы хотим вставить
		// больше чем элемент хранящийся в search_node
		{
			new_node = &search_node->right; // // переходим к правому листу
			// записываем в new_node правый лист от той ноды, которая была записана в search_node
			search_node = search_node->right;  и в search_nodeтоже записываем правый лист от ноды,
			// которая была записана в search_node ранее
		}
		else // если search_node - не NULL и элемент, который мы хотим вставить
		// меньше, чем элемент хранящийся в search_node
		{
			new_node = &search_node->left; // переходим к левому листу
			// записываем в new_node левый лист от той ноды, которая была записана в search_node
			search_node = search_node->left; // и в search_nodeтоже записываем левый лист от ноды, 
			// которая была записана в search_node ранее
		}
	}
}

void print_node(const struct node * search_node) // функция для распечатки дерева начиная с любого узла
{
	if(search_node == NULL) return; // если нода пуста - выходим из функции
	print_node(search_node->left); //  вызываем функцию печати для левого узла ноды
	printf("%d ", search_node->data); // печатаем ноду
	print_node(search_node->right); // вызываем функцию печати для правого узла ноды
}	

void print_tree(const struct tree * my_tree) // функция для распечатки дерева целиком
{
	print_node(my_tree->root);
	// вызываем функцию для распечатки дерева начиная с определенного узла 
}

void destroy(struct node * search_node)
// функция для удаления узла дерева и всех его потомков
{
	if(search_node == NULL) return; //если на вход подали пустую ноду - то и удалять нечего, поэтому выходим из функции
	destroy(search_node->left); // удаляем всех левых потомков
	destroy(search_node->right); // удаляем всех правых потомков
	free(search_node); // чистим память для даной ноды 
} 

void destroy_tree(struct tree * search_tree)
{
	destroy(search_tree->root); 
	free(search_tree);
}

int tree_node_count(struct tree * my_tree) //функция подсчета числа всех доч нод дерева
{
	if(my_tree == NULL) return 0; // если это пустое дерево - возвращаем, что тут 0 нод и завершаем функцию
	return node_count(my_tree->root); // возвращаем количество подсчитаных нод 
}

int node_count(struct node * my_node) //функция для подсчета числа всех дочерних нод для ноды включая её саму
{
	if(my_node == NULL) return 0; // если это пустая нода - возвращаем, что тут 0 нод и завершаем функцию 
	int this_node_count = 1; // this_node_count - переменная, хранящая число всех нод  
	this_node_count += node_count(my_node->left); //вызываем функцию подсчета нод для левого узла текущей ноды 
	this_node_count += node_count(my_node->right); //вызываем функцию подсчета нод для правого узла текущей ноды
	return this_node_count; // возвращаем количество подсчитаных нод
}


int main(int argc, char *argv[]) 
{
	int i;
	struct tree * my_tree = tree_create(); //создаем дерево
	for (i = 0; i < 10; i++)
	{ 
		insert(my_tree, i); //заполняем его цифрами от 0 до 9
	}
	
	printf ("Tree:\n\n");
	print_tree(my_tree); // печатаем дерево
	printf ("\n\nNode count = %d\n", tree_node_count(my_tree)); //выводим на экран число нод дерева
	printf ("\nDelete tree.\n\n");
	destroy_tree(my_tree); // удаляем дерево
	return 0;
}
