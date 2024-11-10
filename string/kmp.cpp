#include<bits/stdc++.h>
using namespace std;

string pat;
vector<vector<int>> dfa;

void kmp(string &pat)
{
	int M = pat.size();
	int R = 256;
	dfa.resize(R);
	for(int i = 0; i < R; i++)
		dfa[i].resize(M);
	dfa[pat[0]][0] = 1;
	for(int X = 0, j = 1; j < M; j++)
	{
		for(int c = 0; c < R; c++)
			dfa[c][j] = dfa[c][X];
		dfa[pat[j]][j] = j + 1;
		X = dfa[pat[j]][X];
	}
}

int search(string &txt)
{
	int i, j, N = txt.size();
	int M = pat.size();
	for(i = 0, j = 0; i < N && j < M; i++)
		j = dfa[txt[i]][j];
	if(j == M) return i - M;
	else	return N;
}

int main()
{
	pat = "ababcacbcaacbbacacabbc";
	string txt = "aacb";
	kmp(pat);
	int temp1 = search(txt);
	printf("%d\n", temp1);
	return 0;
}
