// finding the maximum length of common subsequence using DP;

#include <bits/stdc++.h>
using namespace std;
# define fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define all(v) v.begin(),v.end()
#define mod 1000000007 ;
typedef long long ll;

int dp[4000][4000];
int LCS(string x,string y,int n,int m)
{
if(n==0 | m==0) return dp[n][m] = 0;
if(dp[n][m]!=-1) return dp[n][m];
 
if(x[n-1] == y[m-1] )
	return dp[n][m] = 1 + LCS(x,y,n-1,m-1);
return dp[n][m] = max(LCS(x,y,n-1,m),LCS(x,y,n,m-1));

}
void solve()
{

string x,y;
cin>>x>>y;
memset(dp,-1,sizeof(dp));
cout<<LCS(x,y,x.size(),y.size());
}
int main()
{	
	solve();	
  return 0;
}
