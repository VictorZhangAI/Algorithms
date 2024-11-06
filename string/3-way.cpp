#include<bits/stdc++.h>
using namespace std;

void Sort(vector<string> a)
{
	Sort(a, 0, a.size()-1, 0);
}

void Sort(vector<string> a, int lo, int hi, int d)
{
	if(hi <= lo) return;
	int lt = lo, gt = hi;
	int v = a[lo][d];
	int i = lo + 1;
	while(i <= gt)
	{
		int t = a[i][d];
		if(t < v) exch(a, lt++, i++);
		else if(t > v) exch(a, i, gt--);
		else i++;
	}
	sort(a, lo, lt-1, d);
	if(v >= 0) Sort(a, lt, gt, d+1);
	Sort(a, gt+1, hi, d);
}
