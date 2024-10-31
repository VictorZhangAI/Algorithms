#include<bits/stdc++.h>
using namespace std;

typedef struct edge
{
	int u, v;
}edge;

int n, m;
vector<edge> e;
vector<bool> vis;

bool find_edge(int u, int v)
{
	for(int i = 1; i <= m; ++i)
	{
		if(e[i].u == u && e[i].v == v)
		{
			return true;
		}
	}
	return false;
}

void dfs(int u)
{
	if(vis[u]) return;
	vis[u] = true;
	for(int i = 1; i <= m; ++i)
	{
		if(e[i].u == u)
		{
			dfs(e[i].v);
		}
	}
}

int main()
{
	cin >> n >> m;
	vis.resize(n + 1, false);
	e.resize(m + 1);

	for(int i = 1; i <= m; ++i)
		cin >> e[i].u >> e[i].v;

	return 0;
}
