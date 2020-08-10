#include <bits/stdc++.h>
using namespace std;
int LIS(int a[],int idx,int p,int n,int dp[])
{
    if(idx==0)
        return max(1+LIS(a,idx+1,a[idx],n,dp),LIS(a,idx+1,p,n,dp));
    if(idx == n) return 0;
    if(a[idx] < p) return LIS(a,idx+1,p,n,dp);
    else return  max(1+LIS(a,idx+1,a[idx],n,dp),LIS(a,idx+1,p,n,dp));
    
}
int main() {
    int t;cin>>t;while(t--)
    {
        int n;cin>>n;
        int a[n];
        for(int i = 0;i<n;i++) cin>>a[i];
       
        cout<<LIS(a,0,INT_MIN,n,dp)<<endl;
        
        
    }
	return 0;
}
