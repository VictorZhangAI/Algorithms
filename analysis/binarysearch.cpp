#include<bits/stdc++.h>

int binarysearch(int a[], int key, int n)
{
	int lo = 0, hi = n - 1;
	while(lo <= hi)
	{
		int mid = (hi - lo) / 2;
		if(key < a[mid]) hi = mid - 1;
		else if(key > a[mid]) lo = mid + 1;
		else return mid;
	}
	return -1;
}
