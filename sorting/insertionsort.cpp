#include<bits/stdc++.h>
using namespace std;
vector<int> numbers;

template <typename T>
void exch(vector<T> &a, int i, int j)
{
	T temp = a[i];
	a[i] = a[j];
	a[j] = temp;	
}

bool lt(int a, int b)
{
	if(a < b)
		return true;
	else
		return false;
}

template <typename T>
bool testbench(vector<T> a)
{
	int N = a.size();
	for(int i = 1; i < N; i++)
		if(lt(a[i],  a[i-1]))
			return false;
	return true;
}

void sort(vector<int> &a)
{
	int N = a.size();
	for(int i = 0; i < N; i++)
		for(int j = i; j > 0; j--)
			if(lt(a[j], a[j-1]))
				exch(a, j, j-1);
			else break;
}

int main()
{
	srand(time(NULL));
	for(int i = 0; i <2048 ; i++)
		numbers.push_back(rand()%1001);
	sort(numbers);
	if(testbench(numbers))
		printf("sorted!\n");
	else
		printf("failed!\n");
	return 0;
}
