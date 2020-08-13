// spoj : Neddle in a Haystack
#include <bits/stdc++.h>
using namespace std;

#define mod 1000000009
typedef long long ll;




void solve()
{
	int n; string s, t;
  while ( cin >> n >> s >> t )  // incoming stream of inputs 
  {
		const int p = 31;
		n = s.size(); int m = t.size();
		ll po[m];
		po[0] = 1;
		for (int i = 1; i < m; i++) po[i] = (po[i - 1] * p) % mod;
		ll h_s = 0;
		for (int i = 0; i < n; i++) h_s = (h_s  + (s[i] - 'a' + 1) * po[i]) % mod;
		vector<ll> hash(m + 1, 0);
		for (int i = 0; i < m; i++)
			hash[i + 1] = (hash[i] + (t[i] - 'a' + 1) * po[i]) % mod;
		vector<int> ans;
		for (int i = 0; i <= m - n; i++)
		{
			ll cur = (hash[i + n] - hash[i] + mod ) % mod;
			if (cur == h_s * po[i] % mod) ans.push_back(i);

		}

		for (int i : ans) cout << i << endl;
		if (ans.empty()) cout << endl;
	}


}
int main()
{
	

	solve();

	

	return 0;
}


