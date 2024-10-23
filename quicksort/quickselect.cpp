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

int select(vector<int> &a, int k)
{
	shuffle(a);
	int lo = 0, hi = a.size() - 1;
	while(hi > lo)
	{
		int j = partition(a, lo, hi);
		if(j < k) lo = j + 1;
		else if (j > k) hi = j - 1;
		else return a[k];
	}
	return a[k];
}

int main()
{
	vector<int> numbers;
	for(int i = 2048; i > 0; i--)
		numbers.push_back(i);
	printf("%d %d\n", select(numbers, 35), select(numbers, 70));
	return 0;
}
