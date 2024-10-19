#ifndef MY_STACK
#define MY_STACK

template <class T>
struct Node
{
	T item;
	Node *next;
};

bool op_isEmpty();

bool num_isEmpty();

void op_push(char item);

char op_pop();

void num_push(int item);

int num_pop();

#endif
