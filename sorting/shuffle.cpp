#include<bits/stdc++.h>
using namespace std;

vector<int> deck;

void exch(vector<int> &deck, int i, int j)
{
	int temp = deck[i];
	deck[i] = deck[j];
	deck[j] = temp;
}
	
void shuffle(vector<int> &deck)
{
	srand(time(NULL));
	int N = deck.size();
	for(int i = 0; i < N; i++)
	{
		int r = rand() % (i + 1);
		exch(deck, i, r);
	}
}

int main()
{
	for(int i = 0; i < 10; i++)
		deck.push_back(i);
	shuffle(deck);
	for(int i = 0; i < 10; i++)
		printf("%d\n", deck[i]);
	return 0;
}
