// Given a String, find the longest palindromic subsequence
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;cin>>t;
	while(t--)
	{
	    string a,b;
	    cin>>a;
	    b = a;
	    reverse(a.begin(),a.end());
	    int dp[a.size()+1][a.size()+1];
	    memset(dp,0,sizeof(dp));
	    int n = a.size();
	    for(int i = 1;i<=n;i++)
	    for(int j = 1;j<=n;j++)
	    if(a[i-1] == b[j-1])
	    dp[i][j] = 1 + dp[i-1][j-1];
	    else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
	    
	    cout<<dp[n][n]<<endl;
	}
	return 0;
}
