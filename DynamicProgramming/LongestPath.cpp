// Atcoder DP : G Longest Path

#include <bits/stdc++.h>
using namespace std;
# define fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define all(v) v.begin(),v.end()




int dfs(vector<int> adj[], int n, vector<int> &dp, int i)
{
	if (dp[i] != -1 ) return dp[i];
	if (adj[i].size() == 0 ) return dp[i] = 0;
	int ans = 1;

	for (int j : adj[i])
	{
		int cur = 1;
		cur += dfs(adj, n, dp, j);
		ans = max(cur, ans);

	}

	return dp[i] = ans ;


}
void solve()
{


	int n, m; cin >> n >> m;
	vector<int> adj[n];
	while (m--)
	{
		int a, b; cin >> a >> b;
		adj[--a].push_back(--b);
	}


	vector<int> dp(n, -1);
	for (int i = 0; i < n; i++)
		dfs(adj, n, dp, i);

	cout << *max_element(all(dp));


}



int main()
{
	
	solve();
}
