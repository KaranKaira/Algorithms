include <bits/stdc++.h>
using namespace std;

// binnary exponention (logn)
ll ans(ll a, ll b) {
	if (b == 0)
		return 1;
	ll res = ans(a, b / 2);
	if (b % 2)
		return res * res * a 	;

	return res * res ;
}
void solve()
{
	cout << ans(2, 1000); // 2 ki power 1000
}
int main()
{
	solve();
	return 0;
}



