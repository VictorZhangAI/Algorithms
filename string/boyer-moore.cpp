#include<cstdio>
#include<vector>
#include<string>
using namespace std;

vector<int> right;
string pat;
string txt;

void BoyerMoore(string &pat)
{
	int M = pat.size();
	int R = 256;
	right.resize(R);
	for(int c = 0; c < R; c++)
		right[c] = -1;
	for(int j = 0; j < M; j++)
		right[pat[j]] = j;
}

int search(string &txt)
{
	int N = txt.size();
	int M = pat.size();
	int skip;
	for(int i = 0; i <= N-M; i += skip)
	{
		skip = 0;
		for(int j = M-1; j >= 0; j--)
			if(pat[j] != txt[j])
			{
				skip = j - right[txt[j]];
				if(skip < 1) skip = 1;
				break;
			}
		if(skip == 0) return i;
	}
	return N;
}

int main()
{
	pat = "ababcacbc";
	txt = "bca";
	BoyerMoore(pat);
	int temp1 = search(txt);
	printf("%d\n", temp1);
	return 0;
}
