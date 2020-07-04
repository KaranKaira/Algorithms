#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define all(v) v.begin(),v.end()
#define mod 1000000007 ;
typedef long long ll;



ll in[200000][2];  // 0th colummn is weight of item and 1st column is profit
ll dp[200000][201]; // 0th col is current capacity and 1st col is number of items remaining that can be considered.

int n,W;
ll rec(int w,int i)
{
	if(dp[w][i] != -1) return dp[w][i];  // using already calculated value
	if( w==0 | i == 0) return dp[w][i] =  0; // if 0 capacity and 0 items then answer is already 0

	if(in[i][0] > w) return dp[w][i] = rec(w,i-1);  // if the weight of current item is greater than current capacity ,then we will leave this item and check ahead.

	else {
		dp[w][i] = max(rec(w,i-1), rec(w-in[i][0],i-1) + in[i][1]) ;	 // taking maximum of including and excluding.
		return dp[w][i];
		}

}
		
void solve()
{		
		cin>>n>>W;
		for(int i = 1;i<=n;i++)
			cin>>in[i][0]>>in[i][1];  

		cout<<rec(W,n);  // we want answer for weight W and and no of items n
		
		
}
int main()
{
	memset(dp,-1,sizeof(dp));
	solve();
  return 0;
}



