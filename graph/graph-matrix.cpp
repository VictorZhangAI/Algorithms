#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<bool> vis;
vector<vector<bool>> adj;

bool find_edge(int u, int v){
	return adj[u][v];
}

void dfs(int u)
{
	if(vis[u]) return;
	vis[u] = true;
	for(int v = 1; v <= n; ++v)
	{
		if(adj[u][v])
			dfs(v);
	}
}

int main()
{
	cin >> n >> m;

	vis.resize(n + 1);
	adj.resize(n + 1, vector<bool>(n + 1));

	for(int i = 1; i <= m; ++i)
	{
		int u, v;
		cim >> u >> v;
		adj[u][v] = true;
	}
	return 0;
}
