#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main() {
	int t;cin>>t;while(t--)
	{
	    int n;cin>>n;
	    int a[n];
	    for(int i =0;i<n;i++) cin>>a[i];
	    int x;cin>>x;
	  
	   int dp[n+1][x+1];
	   memset(dp,0,sizeof(dp));
	   for(int i=0;i<=n;i++) dp[i][0] = 1;
	   
	   for(int i=1;i<=n;i++)
	   {
	       for(int j=1;j<=x;j++)
	       {
	           if(a[i-1] <= j )
	           dp[i][j] = (dp[i-1][j-a[i-1]] + dp[i-1][j])%mod;
	           else dp[i][j] = dp[i-1][j];
	       }
	   }
	   cout<<dp[n][x]<<endl;
	}
	return 0;
}
