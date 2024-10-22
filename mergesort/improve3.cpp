/*Improvement3: change the role of a and aux to save time*/

#include<bits/stdc++.h>
#define CUTOFF 7
using namespace std;

template<typename T>
void exch(vector<T> &a, int i, int j)
{
	T temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

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
	for(int k = lo; k <= hi; k++)
		aux[k] = a[k];

	int i = lo, j = mid + 1;
	for(int k = lo; k <= hi; k++)
	{
		if(i > mid) aux[k] = a[j++];
		else if(j > hi) aux[k] = a[i++];
		else if(lt(a[j], a[i])) a[k] = a[j++];
		else aux[k] = a[i++];
	}

}

void insertion(vector<int> &a, int lo, int hi)
{
	int N = a.size();
	for(int i = lo; i <= hi; i++)
		for(int j = i; j > lo; j--)
			if(lt(a[j], a[j-1]))
				exch(a, j, j - 1);
}

void sort(vector<int> &a, vector<int> &aux, int lo, int hi)
{
	if(hi <= (lo + CUTOFF -1))
	{
		insertion(a, lo, hi);
		return;
	}
	int mid = lo + (hi - lo) / 2;
	sort(aux, a, lo, mid);
	sort(aux, a, mid + 1, hi);
	if(!lt(a[mid+1], a[mid])) return;
	merge(a, aux, lo, mid, hi);
}

void sort(vector<int> &a)
{
	aux.resize(a.size() + 1);
	sort(a, aux, 0, a.size() - 1);
}

int main()
{
	vector<int> numbers;
	for(int i = 2047; i >= 0; i--)
		numbers.push_back(i);
	sort(numbers);
	return 0;
}
