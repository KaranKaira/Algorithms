//https://www.codechef.com/problems/REVERSE

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define len(s) int(s.size())

#define ll long long
#define s second




int BFS01(vector<pair<int, int>> adj[] ,  int n)
{

	int dis[n + 1] ;
	for (int i = 1; i <= n; i++) dis[i] = INT_MAX;
	dis[1] = 0;
	deque<int> q;
	q.push_front(1);
	while (len(q))
	{
		int u = q.front();
		q.pop_front();
		for (int i = 0; i < len(adj[u]); i++)
		{
			int v = adj[u][i].f, w = adj[u][i].s;
			if (dis[v] > dis[u] + w)
			{
				dis[v] = dis[u] + w;
				if (w == 1 ) q.push_back(v);
				else q.push_front(v);
			}

		}
	}
	if (dis[n] == INT_MAX ) return -1;
	return dis[n];


}
void  solve()
{
	int n , m ; cin >> n >> m;

	vector<pair<int, int>> adj[n + 1];
	while (m--)
	{
		int a , b; cin >> a >> b;
		adj[a].pb({b, 0});
		adj[b].pb({a, 1});
	}
	cout << BFS01(adj, n) ;
}
int  main()
{
	
		solve();


	return 0;
}

