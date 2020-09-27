#include <bits/stdc++.h>
using namespace std;
#define len(s) int(s.size())
#define pb push_back



int BFS(int i, vector<int> adj[], int n)
{
	int vis[n + 1] ;
	memset(vis, 0, sizeof(vis));
	queue<int> q;
	q.push(i);
	vis[i] = 1;
	int dia = 0 ;
	while (len(q))
	{
		int c = len(q);
		while (c--)
		{
			int f = q.front();
			q.pop();

			for (int child : adj[f])
			{
				if (vis[child] ) continue;
				vis[child] = 1;
				q.push(child);
			}
		}
		dia++;
	}

	return dia - 1;
}
void solve()
{
	int N; cin >> N;
	int ans = 0;
	while (N--)
	{
		int n; cin >> n;
		vector<int> adj[n + 1];
		for (int i = 1; i < n; i++)
		{
			int a, b;
			cin >> a >> b;
			adj[a].pb(b);
			adj[b].pb(a);

		}
		int cur = 0;
		for (int i = 1; i <= n; i++)
		{
			cur = max(cur, BFS(i, adj, n));
		}
		cout << cur << endl;
		ans += cur;
	}
	cout << ans;
}

int main()
{
	
	solve();
}

