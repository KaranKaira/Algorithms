#include <bits/stdc++.h>
using namespace std;

#define read(arr, n)  for (int i = 0; i < n; i++)  cin >> arr[i];
int  a[100001];
int  seg[400040];
int n;
int vis[100001];
int  merge(int a, int b)
{
	return a + b;
}
void buildSeg(int x, int lx, int rx)
{
	if (lx == rx  )
	{
		seg[x] = 0;
		return;
	}
	int m = (lx + rx) / 2;
	buildSeg(2 * x , lx, m);
	buildSeg(2 * x + 1, m + 1, rx);
}
void update(int x, int lx, int rx, int val, int indx)
{
	if (lx == indx && rx == indx)
	{
		vis[indx] = 1;
		seg[x] = 1;
		return;
	}
	int m = (lx + rx) / 2;
	if (indx <= m ) update(2 * x, lx, m, val, indx);
	else update(2 * x + 1, m + 1, rx, val, indx);
	seg[x] = merge(seg[2 * x] , seg[2 * x + 1]);
}
int  query(int x, int lx, int rx, int l, int r)
{
	if (lx >= l && rx <= r) return seg[x];
	else if (lx > r || l > rx) return 0;
	int m = (lx + rx) / 2;
	return query(2 * x , lx, m, l, r ) + query(2 * x + 1, m + 1, rx, l, r);
}
void  solve()
{
	int  m; cin >> n ;
	read(a, n);

	for (int i = 0; i < n; i++)
	{
		cout << query(1, 1, n, a[i] + 1, n) << ' ';
		update(1, 1, n, 1, a[i]);
	}
}
int  main()
{
	solve();

	return 0;
}

