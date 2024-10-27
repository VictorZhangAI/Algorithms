#include<bits/stdc++.h>
#define RED true
#define BLACK false


using namespace std;

typedef struct node
{
	char key[16];
	int val;
	struct node *left;
	struct node *right;
	bool color;
	int N;
}Node;

Node *root;

Node *Min(Node *x)
{
	while(x->left != NULL)
		x = x->left;
	return x;
}

bool isEmpty()
{
	return root == NULL;
}

Node *make_node(char* key, int val, bool color, int N)
{
	Node *n = new Node;
	strcpy(n->key, key);
	n->val = val;
	n->color = color;
	n->N = N;
	return n;
}

int Size(Node *x)
{
	if(x == NULL) return 0;
	else return x->N;
}

bool isRed(Node *x)
{
	if(x == NULL) return BLACK;
	return x->color == RED;
}

int Get(char* key)
{
	Node *x = root;
	while(x != NULL)
	{
		int cmp = strcmp(key, x->key);
		if(cmp < 0) x = x->left;
		else if(cmp > 0) x = x->right;
		else return x->val;		
	}
	return 0;
}

int Get(Node *h, char *key)
{
	Node *x = h;
	while(h != NULL)
	{
		int cmp = strcmp(key, x->key);
		if(cmp < 0) x = x->left;
		else if(cmp > 0) x = x->right;
		else return x->val;
	}
	return 0;
}

Node *rotateLeft(Node *h)
{
	assert(isRed(h->right));
	Node *x = h->right;
	h->right = x->left;
	x->left = h;
	x->color = h->color;
	h->color = RED;
	x->N = h->N;
	h->N = 1 + Size(h->left) + Size(h->right);
	return x;	
}

Node *rotateRight(Node *h)
{
	assert(isRed(h->left));
	Node *x = h->left;
	h->left = x->right;
	x->right = h;
	x->color = h->color;
	h->color = RED;
	h->N = 1 + Size(h->left) + Size(h->right);
	return x;
}

void flipColors(Node *h)
{
	assert(!isRed(h));
	assert(isRed(h->left));
	assert(isRed(h->right));
	h->color = RED;
	h->left->color = BLACK;
	h->right->color = BLACK;
}

Node *moveRedLeft(Node *h)
{
	//Assuming that h is red and both h->left and h->left->left
	//are black, make h->left or one of its children red.
	flipColors(h);
	if(isRed(h->right->left))
	{
		h->right = rotateRight(h->right);
		h = rotateLeft(h);
	}
	return h;
}

Node *moveRedRight(Node *h)
{
	//Assuming that h is red and both h->right and h->right->left
	//are black, make h->right or one of its children red.
	flipColors(h);
	if(!isRed(h->left->left))
		h = rotateRight(h);
	return h;
}

Node *balance(Node *h)
{
	if(isRed(h->right)) h = rotateLeft(h);
	return h;
}

Node *Put(Node *h, char* key, int val)
{
	if(h == NULL) return make_node(key, val, 1, RED);
	int cmp = strcmp(key, h->key);
	if(cmp < 0) h->left = Put(h->left, key, val);
	else if(cmp > 0) h->right = Put(h->right, key, val);
	else h->val = val;

	if(isRed(h->right) && !isRed(h->left)) h = rotateLeft(h);
	if(isRed(h->left) && isRed(h->left->left)) h = rotateRight(h);
	if(isRed(h->left) && isRed(h->right)) flipColors(h);

	h->N = Size(h->left) + Size(h->right) + 1;
	return h;
}

void Put(char* key, int val)
{
	root = Put(root, key, val);
	root->color = BLACK;
}

Node *deleteMin(Node *h)
{
	if(h->left == NULL)
		return NULL;
	if(!isRed(h->left) && !isRed(h->left->left))
		h = moveRedLeft(h);
	h->left = deleteMin(h->left);
	return balance(h);
}

void deleteMin()
{
	if(!isRed(root->left) && !isRed(root->right))
		root->color = RED;
	root = deleteMin(root);
	if(!isEmpty()) root->color = BLACK;
}

Node *deleteMax(Node *h)
{
	if(isRed(h->left))
		h = rotateRight(h);
	if(h->right == NULL)
		return NULL;
	if(!isRed(h->right) && !isRed(h->right->left))
		h = moveRedRight(h);
	h->right = deleteMax(h->right);
	return balance(h);
}

void deleteMax()
{
	if(!isRed(root->left) && !isRed(root->right))
		root->color = RED;
	root = deleteMax(root);
	if(!isEmpty()) root->color = BLACK;
}

Node *Delete(Node *h, char* key)
{
	if(strcmp(key, h->key) < 0)
	{
		if(!isRed(h->left) && !isRed(h->left->left))
			h = moveRedLeft(h);
		h->left = Delete(h->left, key);
	}
	else
	{
		if(isRed(h->left))
			h = rotateRight(h);
		if(strcmp(key, h->key) == 0 && (h->right == NULL))
			return NULL;
		if(!isRed(h->right) && isRed(h->right->left))
			h = moveRedLeft(h);
		if(strcmp(key, h->key) == 0)
		{
			h->val = Get(h->right, Min(h->right)->key);
			strcpy(h->key, Min(h->right)->key);
			h->right = deleteMin(h->right);
		}
		else h->right = Delete(h->right, key);
	}
	return balance(h);
}

void Delete(char* key)
{
	root = Delete(root, key);
	return;
}

void Inorder(Node *x, queue<char*> &a)
{
	if(x == NULL) return;
	Inorder(x->left, a);
	a.push(x->key);
	Inorder(x->right, a);
}

queue<char*> keys()
{
	queue<char*> q;
	Inorder(root, q);
	return q;
}

int main()
{
	Put((char*)"CSharp", 101);
	Put((char*)"Ada", 333);
	Put((char*)"Elixir", 258);
	Put((char*)"Dart", 63);
	Put((char*)"MATLAB", 77);
	Put((char*)"Mathematica", 456);
	int g = Get((char*)"Elixir");
	printf("%d\n", g);
	Delete((char*)"CSharp");
	queue<char*> q = keys();
	while(!q.empty())
	{
		printf("%s\n", q.front());
		q.pop();
	}
	return 0;
}
