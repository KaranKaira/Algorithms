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
	for(int i = 0;i<=m;i++)
	dp[0][i] = 0 ;
	for(int i = 0;i<=n;i++)
		dp[i][0] = 0 ;
	for(int i = 1;i<=n;i++)
	for(int j = 1;j<=m;j++)
	{
		
	    if(x[i-1] == y[j-1])
			dp[i][j] = dp[i-1][j-1] + 1;
		else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
		
	}
	string ans = "";
	int i = n,j = m;	 
	while(i>0 & j>0){
	if(x[i-1] == y[j-1])
	{
		ans = x[i-1] + ans;
		i--;j--;
	}
	else {
		if(dp[i-1][j] >= dp[i][j-1])
			i--;
		else j--;
	}

	}

	cout<<ans<<endl;

	}
	int main()
	{
	solve();	
	return 0;
	}
