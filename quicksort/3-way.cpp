#include<bits/stdc++.h>
using namespace std;

template <typename T>
void exch(vector<T> &a, int i, int j)
{
	T temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

bool testbench(vector<int> a, int lo, int hi)
{
	for(int i = lo + 1; i < hi; i++)
		if(a[i] < a[i - 1])
			return false;
	return true;
}

int partition(vector<int> &a, int lo, int hi)
{
	int i = lo, j = hi + 1;
	while(true)
	{
		while(a[++i] < a[lo])
			if(i == hi) break;

		while(a[lo] < a[--j])
			if(j == lo) break;

		if(i >= j) break;
		exch(a, i, j);	
	}

	exch(a, lo, j);
	return j;
}

void shuffle(vector<int> &a)
{
	srand(time(NULL));
	int N = a.size();
	for(int i = 1; i < N; i++)
	{
		int k = rand() % i;
		exch(a, i, k);
	}
}

void sort(vector<int> &a, int lo, int hi)
{
	if(hi <= lo) return;
	int lt = lo, gt = hi;
	int v = a[lo];        //here 'int' is used instead comparable
	int i = lo;
	while(i <= gt)
	{
		if(a[i] < v) exch(a, lt++, i++);
		else if(a[i] > v) exch(a, i, gt--);
		else i++;
	}

	sort(a, lo, lt - 1);
	sort(a, gt + 1, hi);
}

void sort(vector<int> &a)
{
	shuffle(a);
	sort(a, 0, a.size()-1);
	assert(testbench(a, 0, a.size()-1));
}

int main()
{
	vector<int> numbers;
	for(int i = 200000; i >= 0; i -= 100)
		numbers.push_back(i);
	sort(numbers);
	return 0;
}
