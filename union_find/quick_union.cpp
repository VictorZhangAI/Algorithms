/*Quick-Union approach*/

#include<bits/stdc++.h>

int *UF;
int *id;
int N;

int root(int i)
{
	while(i != id[i])
		i = id[i];
	return i;
}

void Union(int p, int q)
{
	int i = root(p);
	int j = root(q);
	id[i] = j;
}

bool Connected(int p, int q)
{
	if(root(p) == root(q))
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
