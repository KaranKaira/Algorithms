#include <iostream>
using namespace std;
int ans(int a[],int n,int val)
{
    int l = 0,r =n-1,mid;
    while(l<=r)
    {
        mid = l + (r-l)/2;
        if(a[mid] == val) return mid;
        if(mid+1<=r && a[mid+1] > val && a[mid] < val) return mid;
        if(mid == r && a[mid] < val) return mid;
        
        if(a[mid] < val) l = mid+1;
        else r = mid-1;
    }
    return -1;
}
int main() {
	//code
	int t;cin>>t;while(t--)
	{
	    int n,k;cin>>n>>k;
	    int a[n];
	    for(int i=0;i<n;i++) cin>>a[i];
	    cout<<ans(a,n,k)<<endl;
	}
	return 0;
}
