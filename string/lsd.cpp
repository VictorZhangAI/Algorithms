#include<bits/stdc++.h>
using namespace std;

vector<string> a;

void Sort(vector<string> a, int W)
{
	int R = 256;
	int N = a.size();
	vector<string> aux;
	aux.resize(N);

	for(int d = W - 1; d >= 0; d--)
	{
		vector<int> count;
		count.resize(R+1);
		for(int i = 0; i < N; i++)
			count[a[i][d] + 1]++;
		for(int r = 0; r < R; r++)
			count[r + 1] += count[r];
		for(int i = 0; i < N; i++)
			aux[count[a[i][d]]++] = a[i];
		for(int i = 0; i < N; i++)
			a[i] = aux[i];
	}
}

int main()
{
	return 0;
}
