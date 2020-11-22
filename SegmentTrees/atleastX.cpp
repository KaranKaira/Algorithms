#include <bits/stdc++.h>
using namespace std;

#define read(arr, n)  for (int i = 0; i < n; i++)  cin >> arr[i];

int merge(int lchild , int rchild)
{
	return max(lchild, rchild);
}

ll a[100001];
int  seg[400040];
int n;
void buildSeg(int x, int lx, int rx)
{
	if (lx == rx  )
	{
		seg[x] = a[lx];
		return;
	}
	int m = (lx + rx) / 2;
	buildSeg(2 * x , lx, m);
	buildSeg(2 * x + 1, m + 1, rx);
	seg[x] = merge(seg[2 * x], seg[2 * x + 1]);
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
	seg[x] = merge(seg[2 * x ] , seg[2 * x + 1]);


}
int  query(int x, int lx, int rx, int k)
{
	if (lx == rx) {
		if (a[lx] >= k) return lx;
		else return -1;
	}
	int m = (lx + rx) / 2;
	if (k > seg[2 * x] ) return query(2 * x + 1, m + 1, rx, k);
	else return query(2 * x, lx, m, k);

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
			int k; cin >> k;
			cout << query(1, 0, n - 1, k) << endl;
		}

	}
}
int  main()
{
	
	solve();


	return 0;
}

