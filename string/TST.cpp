#include<bits/stdc++.h>
using namespace std;

typedef struct node 
{
	char c;
	int val;
	struct node *left;
	struct node *mid;
	struct node *right;
} Node;

Node *root;

Node *Get(Node *x, string key, int d)
{
	if(x == NULL) return NULL;
	char c = key[d];
	if(c < x->c) return Get(x->left, key, d);
	else if(c > x->c) return Get(x->right, key, d);
	else if(d < key.length() - 1) return Get(x->mid, key, d+1);
	else return x;
}

int Get(string key)
{
	Node *x = Get(root, key, 0);
	if(x == NULL) return -1;
	return x->val;
}

Node *Put(Node *x, string key, int val, int d)
{
	char c = key[d];
	if(x == NULL) 
	{
		x = new Node;
		x->c = c;
	}
	if(c < x->c) x->left = Put(x->left, key, val, 0);
	else if(c > x->c) x->right = Put(x->right, key, val, 0);
	else if(d < key.size() - 1)
		x->mid = Put(x->mid, key, val, d+1);
	else x->val = val;
	return x;
}

void Put(string key, int val)
{
	root = Put(root, key, val, 0);
}

int main()
{
	Put("csharp", 0);
	Put("java", 6);
	Put("elixir", 3);
	Put("python", 5);
	Put("lisp", 1);
	int t1 = Get("elixir");
	int t2 = Get("java");
	int t3 = Get("mathematica");
	cout << t1 << " " << t2 << " " << t3 << endl;
	return 0;
}
