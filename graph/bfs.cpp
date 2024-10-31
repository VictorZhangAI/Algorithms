#include<bits/stdc++.h>
using namespace std;

void bfs(int u)
{
	while(!Q.empty()) Q.pop();
	Q.push(u);
	vis[u] = 1;
	d[u] = 0;
	p[u] = -1;
	while(!Q.empty())
	{
		u = Q.front();
		Q.pop();
		for(int i = head[u]; i; i = e[i].nxt)
		{
			if(!vis[e[i].to])
			{
				Q.push(e[i].to);
				vis[e[i].to] = 1;
				d[e[i].to] = d[u] + 1;
				p[e[i].to] = u;
			}
		}
	}
}

void restore(int x)
{
	vector<int> res;
	for(int v = x; v != -1; v = p[v])
	{
		res.push_back(v);
	}
	reverse(res.begin(), res.end());
	for(int i = 0; i < res.size(); ++i)
		printf("%d", res[i]);
	puts("");
}
