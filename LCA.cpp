// O(n) preprocessing 
// O(logn) query using segment tree
#include <bits/stdc++.h>
using namespace std;
#define len(s) int(s.size())

const int nx = 2000;
int  seg[4 * nx];
int height[nx] , first[nx];
vector<int> euler;
vector<int> graph[nx];
int vis[nx];
void dfs(int i, int h)
{
	vis[i] = 1;
	first[i] = len(euler);
	height[i] = h;
	euler.pb(i);
	for (int j : graph[i])
	{
		if (vis[j]) continue;
		dfs(j, h + 1);
		euler.pb(i);
	}
}
void build(int x, int lx, int rx)
{
	if (lx == rx) {
		seg[x] = euler[lx];
		return;
	}
	int m = (lx + rx) / 2;
	build(2 * x, lx, m);
	build(2 * x + 1, m + 1, rx);
	int l = seg[2 * x];
	int r = seg[2 * x + 1];
	if (height[l] < height[r]) seg[x] = l;
	else seg[x] = r;
}
int query(int x, int lx, int rx, int l, int r)
{
	if (lx >= l && rx <= r)
		return seg[x];
	if (lx > r || l > rx) return -1;
	int m =  (lx + rx) / 2;
	int left = query(2 * x, lx, m, l, r);
	int right = query(2 * x + 1, m + 1, rx, l, r);
	if (left == -1 ) return right;
	if (right == -1 ) return left;

	if (height[left] > height[right] ) return right;
	return left;
}
void  solve()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int m; cin >> m;
		while (m--)
		{
			int child; cin >> child;
			graph[i].pb(child);

		}
	}
	dfs(1, 0);
	build(1, 0, len(euler) - 1);
	int q; cin >> q;
	while (q--)
	{
		int u, v; cin >> u >> v;

		cout << query(1, 0, len(euler) - 1, min(first[u], first[v]) , max(first[u] , first[v])) << endl;
	}
}
int  main()
{
	int ca = 1 ;
	int t; cin >> t; while (t--)
	{
		cout << "Case " << ca++ << ": " << endl;
		solve();

		euler = vector<int> (0);
		memset(height, 0, sizeof(height));
		memset(seg, 0, sizeof(seg));
		memset(first, 0, sizeof(first));
		memset(vis, 0, sizeof(vis));
	}

	return 0;
}

