/*Stack with a linked-list implementation*/

#include<bits/stdc++.h>

typedef struct node 
{
	char *item;
        struct node *next;                                                                                        } Node;

Node *first = NULL;

bool isEmpty()
{
	return first == NULL;
}

void push(char *item)
{
	Node *oldfirst = first;
	first = new Node;
	first->item = item;
	first->next = oldfirst;
}

char *pop()
{
	char *item = first->item;
	first = first->next;
	return item;
}

int main()
{
	push((char *)"I");
	push((char *)"You");
	push((char *)"He");
	char *temp1 = pop();
	char *temp2 = pop();
	char *temp3 = pop();
	puts(temp1);
	puts(temp2);
	puts(temp3);
	return 0;
}
