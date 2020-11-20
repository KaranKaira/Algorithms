
#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define f first
#define s second
#define read(arr, n)  for (int i = 0; i < n; i++)  cin >> arr[i];

ll a[100001];
pair<int, int>  seg[400040];
int n;
void buildSeg(int x, int lx, int rx)
{
	if (lx == rx )
	{
		seg[x].f = a[lx];
		seg[x].s = 1;
		return;
	}
	int m = (lx + rx) / 2;
	buildSeg(2 * x , lx, m);
	buildSeg(2 * x + 1, m + 1, rx);
	int minl = seg[2 * x].f , minlcnt = seg[2 * x ].s;
	int minr = seg[2 * x + 1].f , minrcnt = seg[2 * x + 1].s;
	if (minl < minr) seg[x] = seg[2 * x];
	else if (minl == minr)
		seg[x] = {minl, minlcnt + minrcnt};
	else seg[x] = seg[2 * x + 1];
}
void update(int x, int lx, int rx, int val, int indx)
{
	if (lx == indx && rx == indx)
	{
		a[lx] = val;
		seg[x].f = val;
		seg[x].s = 1;
		return;
	}
	int m = (lx + rx) / 2;
	if (indx <= m ) update(2 * x, lx, m, val, indx);
	else update(2 * x + 1, m + 1, rx, val, indx);
	int minl = seg[2 * x].f , minlcnt = seg[2 * x ].s;
	int minr = seg[2 * x + 1].f , minrcnt = seg[2 * x + 1].s;
	if (minl < minr) seg[x] = seg[2 * x];
	else if (minl == minr)
		seg[x] = {minl, minlcnt + minrcnt};
	else seg[x] = seg[2 * x + 1];


}
pair<ll, ll>  query(int x, int lx, int rx, int l, int r)
{
	if (lx >= l && rx <= r) return seg[x];
	else if (r < lx || l > rx) return {INT_MAX, INT_MAX};
	int m = (lx + rx) / 2;
	auto lans = query(2 * x, lx, m, l, r);
	auto rans = query(2 * x + 1, m + 1, rx, l, r);

	if (lans.f == rans.f) return {lans.f, lans.s + rans.s};
	else if (lans.f > rans.f) return rans;
	else return lans;

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
			pair<ll, ll> p = query(1, 0, n - 1, l, r - 1) ;
			cout << p.f << ' ' << p.s << endl;
		}
	}
}
int  main()
{
	solve();

}

