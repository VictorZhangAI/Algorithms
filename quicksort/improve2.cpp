/*In the same way to use insertion sort in small arrays*/
#include<bits/stdc++.h>
#define CUTOFF 10
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

bool lt(int i, int j)
{
	if(i < j)
		return true;
	else
		return false;
}

int partition(vector<int> &a, int lo, int hi)
{
	int i = lo, j = hi + 1;
	while(true)
	{
		while(lt(a[++i], a[lo]))
			if(i == hi) break;

		while(lt(a[lo], a[--j]))
			if(j == lo) break;

		if(i >= j) break;
		exch(a, i, j);	
	}

	exch(a, lo, j);
	return j;
}

int median(vector<int> a, int lo, int mid, int hi)
{
	int A = a[lo];
	int B = a[mid];
	int C = a[hi];
	if(A > B){
		int temp = A;
		A = B;
		B = temp;
	}
	if(B > C){
		int temp = B;
		B = C;
		C = temp;
	}
	if(B == a[lo])
		return lo;
	if(B == a[mid])
		return mid;
	if(B == a[hi])
		return hi;
	return -1;
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

void insertion(vector<int> &a, int lo, int hi)
{
	for(int i = lo; i <= hi; i++)
		for(int j = i; j >= lo; j--)
			if(lt(a[j], a[j-1]))
				exch(a, j, j-1);
}

void sort(vector<int> &a, int lo, int hi)
{
	if(hi <= lo + CUTOFF - 1)
	{
		insertion(a, lo, hi);
		return;
	}

	int m = median(a, lo, lo+(hi-lo)/2, hi);
	exch(a, lo, m);

	int j = partition(a, lo, hi);
	sort(a, lo, j - 1);
	sort(a, j + 1, hi);
}

void sort(vector<int> &a)
{
	shuffle(a);
	sort(a, 0, a.size()-1);
	assert(testbench(a, 0, a.size()));
}

int main()
{
	vector<int> numbers;
	for(int i = 100000; i > 0; i--)
		numbers.push_back(i);
	sort(numbers);
	return 0;
}
