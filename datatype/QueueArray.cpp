/*An Array-implementation queue that can deal
 * with expand, reduce and fake-overflow*/

#include<bits/stdc++.h>

char **s;
int first = 0;
int last = 0;
int limit = 0;

void capacity(int cap)
{
	limit = cap;
	s = (char**)malloc((sizeof(char*)) * limit);
	for(int i = 0; i < limit; i++)
		s[i] = (char*)malloc(sizeof(char) * 100);
}

bool isEmpty()
{
	return first == 0;
}

void enqueue(char *item)
{
	if(last == (limit - 1)){
		s = (char**)realloc(s, (sizeof(char*)) * limit * 2);
		for(int i = 0; i < limit * 2; i++)
			s[i] = (char*)malloc(sizeof(char) * 100);
		limit *= 2;
	}
	s[last++] = item;
}

char *dequeue()
{
	char *item = s[first++];
	if(first == last)
		first = last = 0;
	s[first-1] = NULL;
	if(last > 0 && last == limit / 4){
		s = (char**)realloc(s, (sizeof(char*)) * limit / 2);
		for(int i = 0; i < limit / 2; i++)
			s[i] = (char*)malloc(100 * sizeof(char));
		limit /= 2;
	}
	return item;
}

int main()
{
	capacity(2);
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
