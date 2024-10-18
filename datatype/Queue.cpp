/*Queue implementation with linked list*/

#include<bits/stdc++.h>

typedef struct node 
{
	char *item;
	struct node *next;
}Node;

Node* first;
Node* last;

bool isEmpty()
{
	return first == NULL;
}

void enqueue(char *item)
{
	Node *oldlast = last;
	last = new Node;
	last->item = item;
	last->next = NULL;
	if(isEmpty())
		first = last;
	else
		oldlast->next = last;
}

char *dequeue()
{
	char *item = first->item;
	first = first->next;
	if(isEmpty())
		last = NULL;
	return item;
}

int main()
{
	enqueue((char*)"I");
	enqueue((char*)"You");
	enqueue((char*)"He");
	char *temp1 = dequeue();
	char *temp2 = dequeue();
	char *temp3 = dequeue();
	puts(temp1);
	puts(temp2);
	puts(temp3);
	return 0;
}
