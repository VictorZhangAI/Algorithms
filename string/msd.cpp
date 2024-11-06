#include<bits/stdc++.h>
using namespace std;

void Sort(vector<string> a)
{
	string aux;
	Sort(a, aux, 0, a.size()-1, 0);
}

void Sort(vector<string> a, vector<string> aux, int lo, int hi, int d)
{
	if(hi <= lo) return;
	vector<int> count;
	count.resize(R+2);
	for(int i = lo; i <= hi; i++)
		count[a[i][d] + 2]++;
	for(int r = 0; r < R+1; r++)
		count[r+1] += count[r];
	for(int i = lo; i <= hi; i++)
		aux[count[a[i][d] + 1]++] = a[i];
	for(int i = lo; i <= hi; i++)
		a[i] = aux[i - lo];

	for(int i = lo; i <= hi; i++)
		a[i] = aux[i - lo];

	for(int r = 0; r < R; r++)
		Sort(a, aux, lo + count[r], lo + count[r+1] - 1, d + 1);
}
