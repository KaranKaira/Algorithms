// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define read(arr, n)  for (int i = 0; i < n; i++)  cin >> arr[i];

struct Node {
	ll max_sum , sum, pre_sum , suf_sum;
	Node() {}
	Node(ll x, ll y, ll z, ll t) : max_sum(x) , sum(y), pre_sum(z) , suf_sum(t) {}
};
Node merge(Node lchild , Node rchild)
{
	Node res ;
	res.max_sum = max({ lchild.max_sum, rchild.max_sum , lchild.suf_sum + rchild.pre_sum
	                  });
	res.sum = lchild.sum + rchild.sum;
	res.pre_sum = max({lchild.pre_sum , rchild.pre_sum + lchild.sum});
	res.suf_sum = max({ rchild.suf_sum , rchild.sum + lchild.suf_sum});
	return res;
}
ll a[100001];
Node seg[400040];
int n;
void buildSeg(int x, int lx, int rx)
{
	if (lx == rx )
	{
		seg[x].max_sum = max(0ll, a[lx]);
		seg[x].suf_sum = a[lx];
		seg[x].pre_sum = seg[x].sum = a[lx] ;
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
		seg[x].max_sum = max(0, val);
		seg[x].sum = val;
		seg[x].pre_sum = seg[x].suf_sum = val;
		return;
	}
	int m = (lx + rx) / 2;
	if (indx <= m ) update(2 * x, lx, m, val, indx);
	else update(2 * x + 1, m + 1, rx, val, indx);
	seg[x] = merge(seg[2 * x ] , seg[2 * x + 1]);


}
Node  query(int x, int lx, int rx, int l, int r)
{
	if (lx >= l && rx <= r) return seg[x];
	else if (r < lx || l > rx) return Node(0, 0, 0, 0);
	int m = (lx + rx) / 2;
	auto lans =  query(2 * x, lx, m, l, r);
	auto rans =  query(2 * x + 1, m + 1, rx, l, r);

	return  merge(lans, rans);

}
void  solve()
{
	int  m; cin >> n >> m;
	read(a, n);
	buildSeg(1, 0, n - 1);


	Node cur = query(1, 0, n - 1, 0, n - 1);
	cout <<  cur.max_sum << endl;

	while (m--)
	{
		ll idx , val;
		cin >> idx >> val;
		update(1, 0, n - 1, val, idx);
		cur = query(1, 0, n - 1, 0, n - 1);
		cout <<  cur.max_sum << endl;

	}
}
int  main()
{
	solve();

}

