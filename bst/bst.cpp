#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
	char key[10];
	int val;
	int count;
	struct node *left;
	struct node *right;
}Node;

Node* root;

Node *Make_node(char* key, int val)
{
	Node *n_node = new Node;
	strcpy(n_node->key, key);
	n_node->val = val;
	return n_node;
}

Node *Make_node(char* key, int val, int count)
{
	Node *n_node = new Node;
	strcpy(n_node->key, key);
	n_node->val = val;
	n_node->count = count;
	return n_node;
}

Node *Min(Node *x)
{
	while(x->left != NULL)
		x = x->left;
	return x;
}

int Size(Node *x)
{
	if(x == NULL) return 0;
	return x->count;
}

int Size()
{
	return Size(root);
}

int Get(char* key)
{
	Node* x = root;
	while(x != NULL)
	{
		int cmp = strcmp(key, x->key);
		if(cmp < 0) x = x->left;
		else if(cmp > 0) x = x->right;
		else return x->val;
	}
	return -1;
}

Node *Put(Node *x, char* key, int val)
{
	if(x == NULL)
		return Make_node(key, val, 1);
	int cmp = strcmp(key, x->key);
	if(cmp < 0) x->left = Put(x->left, key, val);
	else if(cmp > 0) x->right = Put(x->right, key, val);
	else x->val = val;
	x->count = 1 + Size(x->left) + Size(x->right);
	return x;
}

void Put(char* key, int val)
{
	root = Put(root, key, val);
}

int Rank(char* key, Node* x)
{
	if(x == NULL) return 0;
	int cmp = strcmp(key, x->key);
	if(cmp > 0) return Rank(key, x->left);
	else if (cmp < 0) return 1 + Size(x->left) + Rank(key, x->right);
	else return Size(x->left);
}

int Rank(char* key)
{
	return Rank(key, root);
}

Node *Floor(Node *x, char *key)
{
	if(x == NULL) return NULL;
	int cmp = strcmp(key, x->key);
	if(cmp == 0) return x;
	if(cmp < 0) return Floor(x->left, key);
	Node *t = Floor(x->right, key);
	if(t != NULL) return t;
	else return x;
}

char* Floor(char* key)
{
	Node *x = Floor(root, key);
	if(x == NULL) return NULL;
	return x->key;
}

void Inorder(Node *x, queue<char*> &q)
{
	if(x == NULL) return;
	Inorder(x->left, q);
	q.push(x->key);
	Inorder(x->right, q);
}

queue<char*> keys()
{
	queue<char*> q;
	Inorder(root, q);
	return q;
}

Node *deleteMin(Node *x)
{
	if(x->left == NULL) return x->right;
	x->left = deleteMin(x->left);
	x->count = 1 + Size(x->left) + Size(x->right);
	return x;
}

void deleteMin()
{
	root = deleteMin(root);
}

Node *Delete(Node *x, char* key)
{
	if(x == NULL) return NULL;
	int cmp = strcmp(key, x->key);
	if(cmp < 0) x->left = Delete(x->left, key);
	else if(cmp > 0) x->right = Delete(x->right, key);
	else {
		if(x->right == NULL) return x->left;
		if(x->left == NULL) return x->right;

		Node *t = x;
		x = Min(t->right);
		x->right = deleteMin(t->right);
		x->left = t->left;
	}

	x->count = Size(x->left) + Size(x->right) + 1;
	return x;
}

void Delete(char* key)
{
	root = Delete(root, key);
}

int main()
{
	Put((char*)"time", 317);
	Put((char*)"class", 24);
	Put((char*)"rank", 58);
	Put((char*)"scheme", 60);
	Put((char*)"csharp", 33);
	Put((char*)"newton", 40);
	Put((char*)"windows", 78);
	int temp1 = Get((char*)"csharp");
	int temp2 = Get((char*)"newton");
	printf("%d %d\n", temp1, temp2);
	Delete((char*)"csharp");
	Delete((char*)"newton");
	queue<char*> q = keys();
	while(q.size() != 0)
	{
		printf("%s\n", q.front());
		q.pop();
	}
	return 0;
}
