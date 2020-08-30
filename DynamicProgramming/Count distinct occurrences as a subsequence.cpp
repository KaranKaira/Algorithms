#include <iostream>
using namespace std;

int main() {
	//code
	int t;cin>>t;while(t--)
	{
	    string a,b;cin>>a>>b;
	    int n = a.size(),m = b.size();
	    int dp[m+1][n+1];
	    for(int i=1;i<=m;i++)dp[i][0] = 0;
	    for(int i=0;i<=n;i++) dp[0][i] = 1;
	    
	    for(int i=1;i<=m;i++)
	    {
	        for(int j = 1;j<=n;j++)
	        {
	            if(b[i-1]  != a[j-1]) dp[i][j] = dp[i][j-1];
	            else dp[i][j]= dp[i-1][j-1] + dp[i][j-1];
	        }
	    }
	        
	         cout<<dp[m][n]<<endl;
     }
	return 0;
}
