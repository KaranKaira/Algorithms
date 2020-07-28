#include <iostream>
using namespace std;
int ans = 0;
long long merge(int a[],int l,int mid,int r)
{
    long long c = 0;
    int i,j,k;
    
    int s1 =  mid - l+1,s2 = r - mid;
    int L[s1],R[s2];
    for( i=0;i<s1;i++)
        L[i] = a[l+i];
    for(j = 0;j<s2;j++)
        R[j] = a[j+mid+1];
    i = 0,j=0,k = l;
    while(i < s1 && j < s2)
    {
        if(L[i] <= R[j])
            a[k++] = L[i++];
        
        else {
            a[k++] = R[j++];
            c+= s1 - i;
        }
    }
    while(i < s1)
    {
        a[k++] = L[i++];
    }
    while(j < s2) a[k++] = R[j++];
    
    
    
    return c;
    
}
long long mergesort(int a[],int l,int r)
{
    if(l>=r) return 0;
    int mid = l + (r-l)/2;
    long long ans1 = mergesort(a,l,mid);
    long long ans2 = mergesort(a,mid+1,r);
    long long ans3 = merge(a,l,mid,r);
    return ans1 + ans2 + ans3;
    
}
int main() {
	
	    int n;cin>>n;
	    int a[n];
	    for(int i = 0;i<n;i++) cin>>a[i];
	    
	    cout<<mergesort(a,0,n-1)<<endl;
	
	return 0;
}
