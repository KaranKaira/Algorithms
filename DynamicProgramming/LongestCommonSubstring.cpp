// Longest Common Substring using topdown approach

#include <bits/stdc++.h>
using namespace std;
# define fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define all(v) v.begin(),v.end()
#define mod 1000000007 ;
typedef long long ll;

int dp[4000][4000];
void solve()
{

string x,y;
cin>>x>>y;
int n = x.size(), m = y.size();
for(int i = 0;i<m;i++)
dp[0][i] = 0 ;
for(int i = 0;i<n;i++)
	dp[i][0] = 0 ;
for(int i = 1;i<=n;i++)
for(int j = 1;j<=m;j++)
{
	
    if(x[i-1] == y[j-1])
		dp[i][j] = 1 + dp[i-1][j-1];
	else dp[i][j] = 0;
}
cout<<dp[n][m];
}
int main()
{
	solve();	
	return 0;
}
