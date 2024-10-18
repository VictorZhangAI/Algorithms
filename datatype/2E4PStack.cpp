/*Finally improved Stack*/

#include<bits/stdc++.h>

char **s;
int N = 0;
int limit = 0;

void capacity(int cap)
{
	limit = cap;
	s = (char**)malloc((sizeof(char)) * limit * 100);
}

bool isEmpty()
{
	return N == 0;
}

void push(char *item)
{
	if(N == (limit - 1)){
		s = (char**)realloc(s, (sizeof(char)) * limit * 2 * 100);
		limit *= 2;
	}
	s[N++] = item;
}

char *pop()
{
	char *item = s[--N];
	s[N] = NULL;
	if(N > 0 && N == limit / 4){
		s = (char**)realloc(s, (sizeof(char)) * limit / 2 * 100);
		limit /= 2;
	}
	return item;
}

int main()
{
	capacity(2);
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
