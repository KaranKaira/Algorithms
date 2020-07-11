// length of Longest Common Supersequence of 2 strings
#include <iostream>
using namespace std;

int main() {
	//code
	int t;cin>>t;
	while(t--)
	{
	    string a,b;cin>>a>>b;
	    int dp[a.size()+1][b.size()+1];
	    int n = a.size(),m = b.size();
	    
	    for(int i = 0;i<=n;i++)
	    dp[i][0] = 0;
	    for(int i = 0;i<=m;i++)
	    dp[0][i] = 0;
	    for(int i= 1;i<=n;i++)
	    for(int j = 1;j<=m;j++)
	    {
	        if(a[i-1] == b[j-1])
	        dp[i][j] = 1 + dp[i-1][j-1];
	        else 
	        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
	    }
	    cout<< n + m - dp[n][m] <<endl;
	}
	return 0;
}
