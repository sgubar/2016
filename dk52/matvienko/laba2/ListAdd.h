
typedef struct Node
{
	int value;
	struct Node *next;
}Node;

Node *createList(int k);

void AddList(Node **head, Node **tail, int data)
