#include<bits/stdc++.h>
#define DATA_SIZE 2048
using namespace std;

vector<int> numbers;

int count()
{
	int N = numbers.size();
	int count = 0;
	for(int i = 0; i < N; i++)
		for(int j = i + 1; j < N; j++)
			for(int k = i + 2; k < N; k++)
				if(numbers[i] + numbers[j] + numbers[k] == 0)
					count++;
	return count;
}

int main()
{
	srand((unsigned)time(NULL));
	for(int i = 0; i < DATA_SIZE; i++){
		numbers.push_back(rand() % 200 - 100);
	}
	clock_t start = clock();
	int pairs = count();
	clock_t end = clock();
	printf("There are %d pairs of 3-sums.\n", pairs);
	printf("Time used: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
	return 0;
}
