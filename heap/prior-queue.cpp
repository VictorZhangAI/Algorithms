#include<bits/stdc++.h>
using namespace std;

template<typename T>
void exch(vector<T> &a, int i, int j)
{
	T temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

vector<int> pq;
int N = 0;

void capacity(int c)
{
	pq.resize(c);
}

bool isEmpty()
{
	return N == 0;
}

void insert(int x)
{
	pq[N++] = x;
}

int delMax()
{
	int max = 0;
	for(int i = 1; i < N; i++)
		if(pq[max] < pq[i]) max = i;
	exch(pq, max, N-1);
	return pq[--N];
}

int main()
{
	capacity(5);
	insert(1);
	insert(4);
	insert(2);
	insert(3);
	int temp = delMax();
	printf("%d\n", temp);
	return 0;
}
