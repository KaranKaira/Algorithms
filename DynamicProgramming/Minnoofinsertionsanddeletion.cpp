// Min no of insertions and deletion to make string a equal to b
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	 int n,m;cin>>n>>m;
	    string a,b;cin>>a>>b;
	    int dp[n+1][m+1];
	    memset(dp,0,sizeof(dp));
	    for(int i = 1;i<=n;i++)
	    for(int j = 1;j<=m;j++)
	    if(a[i-1] == b[j-1])
	    dp[i][j] = 1 + dp[i-1][j-1];
	    else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
	    
	    cout<< n + m - 2*dp[n][m] << endl;
	
	return 0;
}
