#include<bits/stdc++.h>
using namespace std;

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
	for(int i = 0; i < a.size(); i++)
		printf("%d \n", a[i]);

	assert(testbench(a, lo, hi));
}

int main()
{
	vector<int> numbers;
	vector<int> aux;
	numbers = {1, 3, 5, 2, 4, 6};
	aux.resize(numbers.size());
	merge(numbers, aux, 0, 2, 5);
	return 0;
}
