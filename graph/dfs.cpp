#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;

void dfs(int s)
{
	stack<int> st;
	st.push(s);
	vis[s] = true;

	while(!st.empty()){
		int u = st.top();
		st.pop();

		for(int v : adj[u]) {
			if(!vis[v]) {
				vis[v] = true;
				st.push(v);
			}
		}
	}
}

void dfs(const int u)
{
	vis[u] = true;
	for(int v : adj[u])
		if(!vis[v])
			dfs(v);
}

void dfs(int u)
{
	vis[u] = 1;
	for(int i = head[u]; i; i = e[i].x)
	{
		if(!vis[e[i].t]){
			dfs(v);
		}
	}
}


