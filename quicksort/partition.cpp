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

int main()
{
	vector<int> numbers = {3, 1, 2, 4, 5};
	int P = partition(numbers, 0, 6);
	printf("%d\n", P);
	return 0;
}
