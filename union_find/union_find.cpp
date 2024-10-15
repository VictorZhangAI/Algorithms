/*The slow way to design the union-find set*/

#include<bits/stdc++.h>

int *UF;
int *id;
int N;

void Union(int p, int q)
{
	int temp;
	for(int i = 0; i < N; i++)
	{
		temp = id[q];
		for(int i = 0; i < N; i++)
		{
			if(id[i] == temp)
				id[i] = id[p];
		}
	}
}

bool Connected(int p, int q)
{
	if(id[p] == id[q])
		return true;
	else
		return false;
}

using namespace std;
int main(){
	scanf("%d", &N);
	UF = (int *)malloc(sizeof(int) * (N+1));
	id = (int *)malloc(sizeof(int) * (N+1));

	for(int i = 0; i < N; i++)
	{
		UF[i] = i;
		id[i] = i;
	}

	int p, q;

	while(scanf("%d%d", &p, &q) != EOF)
	{
		if(!Connected(p, q))
			Union(p, q);
		for(int i = 0; i < N; i++)
		{
			printf("%d ", id[i]);
		}
		printf("\n");
	}

	free(UF);
	free(id);

	return 0;
}
