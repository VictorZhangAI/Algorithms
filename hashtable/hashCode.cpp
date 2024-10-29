#include<bits/stdc++.h>

using namespace std;

typedef struct Transaction
{
	char who[20];
	int when;
	double amount;
}Transaction;

int M = 97;

typedef struct node
{
	int key;
	char* value;
	struct node *next;
}Node;

Node *table[M];

int hashCode(int value)
{
	return value;
}

int hashCode(bool value)
{
	if(value) return 1231;
	else return 1237;
}

int hashCode(double value)
{
	long bits = (long)value;
	return (int)(bits ^ (bits >> 32));
}

int hashCode(char* value)
{
	int hash = 0;
	int h = hash;
	if(h != 0) return h;
	int len = strlen(value);
	for(int i = 0; i < len; i++)
		h = value[i] + (31 * h);
	hash = h;
	return h;
}

int hashCode(Transaction value)
{
	int hash = 17;
	hash = 31 * hash + hashCode(value.who);
	hash = 31 * hash + hashCode(value.when);
	hash = 31 * hash + hashCode(value.amount);
	return hash;
}

int Hash(char* key)
{
	return (hashCode(key) & 0x7FFFFFFFF) % M;
}

char* Get(int key)
{
	int i = Hash(key);
	for(Node *x = table[i], x != NULL; x = x->next)
		if(key == x->key) return x->val;
	return NULL;
}

int main()
{
	int k = Hash((char*)"CSharp");
	return 0;
}
