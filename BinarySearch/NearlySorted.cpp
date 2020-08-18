#include <bits/stdc++.h>
using namespace std;


void NearlySortedBinarySearch(int a[],int n,int val)
{
	int l = 0,r = n-1,mid;
	while(l<=r)
	{
		mid = l + (r-l)/2;
		if(a[mid] == val ) return mid;
		if(mid-1>l && a[mid-1] == val) return mid-1;
		if(mid+1<r && a[mid+1] == val) return mid+1;

		if(a[mid] < val ) l = mid+2;
		else r = mid-2;
	}

	
	return -1;
}


int main()
{
	// formalities...
}
