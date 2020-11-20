#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define read(arr, n)  for (int i = 0; i < n; i++)  cin >> arr[i];

ll a[100001];
ll seg[400040];
int n;
void buildSeg(int x, int lx, int rx)
{
	if (lx == rx )
	{
		seg[x] = a[lx];
		return;
	}
	int m = (lx + rx) / 2;
	buildSeg(2 * x , lx, m);
	buildSeg(2 * x + 1, m + 1, rx);
	seg[x] = seg[2 * x + 1] + seg[2 * x ];
}
void update(int x, int lx, int rx, int val, int indx)
{
	if (lx == indx && rx == indx)
	{
		a[lx] = val;
		seg[x] = val;
		return;
	}
	int m = (lx + rx) / 2;
	if (indx <= m ) update(2 * x, lx, m, val, indx);
	else update(2 * x + 1, m + 1, rx, val, indx);
	seg[x] = seg[2 * x] + seg[2 * x + 1];
}
ll query(int x, int lx, int rx, int l, int r)
{
	if (lx >= l && rx <= r) return seg[x];
	else if (r < lx || l > rx) return 0;
	int m = (lx + rx) / 2;
	return query(2 * x, lx, m, l, r) + query(2 * x + 1, m + 1, rx, l, r);
}
void  solve()
{
	int  m; cin >> n >> m;
	read(a, n);
	buildSeg(1, 0, n - 1);

	while (m--)
	{
		int q; cin >> q;
		if (q == 1)
		{
			int idx, val; cin >> idx >> val;
			update(1, 0, n - 1, val, idx);
		}
		else {
			int l, r; cin >> l >> r;
			cout << query(1, 0, n - 1, l, r - 1) << endl;
		}
	}
}
int  main()
{
	IO();
	solve();


}

