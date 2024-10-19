#include"Stack.h"
#include<cstddef>

Node<char> *op_first;
Node<int> *num_first;

bool op_isEmpty()
{
	return op_first == NULL;
}

bool num_isEmpty()
{
	return num_first == NULL;
}

void op_push(char item)
{
	Node<char> *oldfirst = op_first;
	op_first = new Node<char>;
	op_first->item = item;
	op_first->next = oldfirst;
}

char op_pop()
{
	char item = op_first->item;
	op_first = op_first->next;
	return item;
}

void num_push(int item)
{
	Node<int> *oldfirst = num_first;
	num_first = new Node<int>;
	num_first->item = item;
	num_first->next = oldfirst;
}

int num_pop()
{
	int item = num_first->item;
	num_first = num_first->next;
	return item;
}
