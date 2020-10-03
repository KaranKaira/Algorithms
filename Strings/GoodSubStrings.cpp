// https://codeforces.com/problemset/problem/271/D
// very good 2 hashes used to minimizes collisions

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
# define fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define mod1 1000000009
#define mod 1000000007
#define Mod 998244353

typedef long long ll;



void solve()
{

	string s; cin >> s;
	int n = s.size();
	int p = 31;
	int p2 = 37;
	string bad; cin >> bad;
	int k; cin >> k;
	vector<ll> powp(n), powp1(n);
	powp[0] = 1;
	powp1[0] = 1;
	for (int i = 1; i < n; i++)
	{
		powp[i] = powp[i - 1] * p % mod;
		powp1[i] = powp1[i - 1] * p2 % mod1;
	}


	vector<int> countbad(n, 0);
	countbad[0] = (bad[s[0] - 'a'] == '0');
	for (int i = 1; i < n; i++)
		countbad[i] = countbad[i - 1] + (bad[s[i] - 'a'] == '0');

	ll ans = 0;

	vector<ll> hash(n + 1, 0), hash1(n + 1, 0);
	for (int i = 0; i < n; i++)
	{
		hash[i + 1] = (hash[i] + (s[i] - 'a' + 1) * powp[i]) % mod;
		hash1[i + 1] = (hash1[i] + (s[i] - 'a' + 1) * powp1[i]) % mod1;
	}
	map<pair<ll, ll>, bool> ma;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= n - i; j++)
		{
			ll hash_now = (hash[j + i] - hash[j] + mod) % mod;
			hash_now = (hash_now * powp[n - j - 1]) % mod;

			ll hash_now1 = (hash1[j + i ] - hash1[j] + mod1 ) % mod1;
			hash_now1 = (hash_now1 * powp1[n - j - 1]) % mod1;

			if (ma[ {hash_now, hash_now1}] == false)
			{
				ma[ {hash_now, hash_now1}] = true;
				int badletters = countbad[j + i - 1] - (j ? countbad[j - 1] : 0);
				if (badletters <= k )
					ans++;
			}
		}
	}
	cout << ans ;
}


int  main()
{
	solve();


}

