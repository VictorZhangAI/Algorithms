#include<bits/stdc++.h>
using namespace std;

int lcp(string s, string t)
{
	int N = min(s.size(), t.size());
	for(int i = 0; i < N; i++)
		if(s[i] != t[i])
			return i;
	return N;
}

int main()
{
	string s = "prefetch";
	string t = "prefix";
	printf("%d\n", lcp(s, t));
	return 0;
}
