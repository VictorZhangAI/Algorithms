/*Naive Approach of Stack with Array*/

#include<bits/stdc++.h>

char **s;
int N = 0;

void capacity(int cap)
{
	s = (char**)malloc((sizeof(char)) * cap * 100);
}

bool isEmpty()
{
	return N == 0;
}

void push(char *item)
{
	s[N++] = item;
}

char *pop()
{
	return s[--N];
}

int main()
{
	capacity(5);
	push((char*)"I");
	push((char*)"You");
	push((char*)"He");
	char *temp1 = pop();
	char *temp2 = pop();
	char *temp3 = pop();
	puts(temp1);
	puts(temp2);
	puts(temp3);
	return 0;
}
