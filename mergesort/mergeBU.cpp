#include<bits/stdc++.h>
using namespace std;

vector<int> aux;

bool lt(int i, int j)
{
	if(i < j)
		return true;
	else
		return false;
}

bool testbench(vector<int> a, int lo, int hi)
{
	for(int i = lo + 1; i <= hi; i++)
		if(a[i] < a[i - 1])
			return false;
	return true;
}

void merge(vector<int> &a, vector<int> &aux, int lo, int mid, int hi)
{
	assert(testbench(a, lo, mid));
	assert(testbench(a, mid + 1, hi));
	
	for(int k = lo; k <= hi; k++)
		aux[k] = a[k];

	int i = lo, j = mid + 1;
	for(int k = lo; k <= hi; k++)
	{
		if(i > mid) a[k] = aux[j++];
		else if(j > hi) a[k] = aux[i++];
		else if(lt(aux[j], aux[i])) a[k] = aux[j++];
		else a[k] = aux[i++];
	}

	assert(testbench(a, lo, hi));
}

void sort(vector<int> &a)
{
	aux.resize(a.size() + 1);
	int N = a.size();
	for(int sz = 1; sz < N; sz = sz + sz)
		for(int lo = 0; lo < N-sz; lo += sz + sz)
			merge(a, aux, lo, lo+sz-1, min(lo+sz+sz-1, N-1));
}

int main()
{
	vector<int> numbers;
	for(int i = 2047; i >= 0; i--)
		numbers.push_back(i);
	sort(numbers);
	return 0;
}
