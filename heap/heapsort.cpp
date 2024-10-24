#include<bits/stdc++.h>
using namespace std;

template<typename T>
void exch(vector<T> &a, int i, int j)
{
	T temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

bool lt(vector<int> &a, int i, int j)
{
	if(a[i] < a[j])
		return true;
	else
		return false;
}

bool testbench(vector<int> &a, int lo, int hi)
{
	for(int i = lo + 1; i < hi; i++)
		if(lt(a, i, i - 1))
			return false;
	return true;
}

vector<int> pq;
int N = 0;

void swim(int k)
{
	while(k > 1 && lt(pq, k/2, k))
	{
		exch(pq, k, k/2);
		k = k/2;
	}

}

void capacity(int c)
{
	pq.resize(c + 1);
}

bool isEmpty()
{
	return N == 0;
}

void insert(int x)
{
	pq[++N] = x;
	swim(N);
}

void sink(int k)
{
	while(2 * k <= N)
	{
		int j = 2 * k;
		if(j < N && lt(pq, j, j + 1)) j++;
		if(!lt(pq, k, j)) break;
		exch(pq, k, j);
		k = j;
	}
}

void sink(int k, int N)
{
	while(2 * k <= N)
	{
		int j = 2 * k;
		if(j < N && lt(pq, j, j + 1)) j++;
		if(!lt(pq, k, j)) break;
		exch(pq, k, j);
		k = j;
	}
}

int delMax()
{
	int max = pq[1];
	exch(pq, 1, N--);
	sink(1);
	pq[N + 1] = 0;
	return max;
}

void sort(vector<int> &a)
{
	int n = a.size();
	for(int k = n / 2; k >= 1; k--)
	{
		sink(k, n);
	}
	while(n > 1)
	{
		exch(pq, 1, n--);
		sink(1, n);
	}
}

int main()
{
	capacity(5000);
	for(int i = 4096; i > 0; i--)
	{
		insert(i);
	}
	sort(pq);
	assert(testbench(pq, 0, pq.size()));
	return 0;
}
