#include<bits/stdc++.h>

int M = 30001;
char* vals[M];
int keys[M];

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

int Hash(int key)
{
	return (key & 0x7FFFFFFF) % M;
}

void Put(int key, char* val)
{
	int i;
	for(i = Hash(key); keys[i] != NULL; i = (i + 1) % M)
		if(keys[i] == key)
			break;
	keys[i] = key;
	strcpy(vals[i], val);
}

char* Get(int key)
{
	for(int i = Hash(key); keys[i] != NULL; i = (i + 1) % M)
		if(keys[i] == key)
			return vals[i];
	return NULL;
}

int main()
{
	Put(1, (char*)"CSharp");
	Put(2, (char*)"Fortran");
	Put(3, (char*)"Java");
	return 0;
}
