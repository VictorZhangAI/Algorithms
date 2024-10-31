#include<bits.stdc++.h>
using namespace std;

int n, m;
vector<bool> vis;
vector<int> head, nxt, to;

void add(int u, int v)
{
	nxt.push_back(head[u]);
	head[u] = to.size();
	to.push_back(v);
}

bool find_edge(int u, int v)
{
	for(int i = head[u], ~i; i = nxt[i])
	{
		if(to[i] == v)
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
	for(int i = head[u]; ~i; i = nxt[i]) dfs(to[i]);
}

int main()
{
	cin >> n >> m;

	vis.resize(n + 1; false);
	head.resize(n + 1; -1);

	for(int i = 1; i <= m; ++i)
	{
		int u, v;
		cin >> u >> v;
		add(u, v);
	}
	return 0;
}
