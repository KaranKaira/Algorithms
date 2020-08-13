#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;

// number of unique substring in a string
void solve()
{
	string s; cin >> s;
	int n = s.size();

	vector<ll> hash(n + 1, 0); //hash[i] is hash for prefix of length i;
	int pow_p[n] ;
	pow_p[0] = 1 ;
	int p = 31;
	for (int i = 1; i < n; i++) pow_p[i] = pow_p[i - 1] * p % mod;
	for (int i = 0; i < n; i++)
		hash[i + 1] = (hash[i] + (s[i] - 'a' + 1) * pow_p[i]) % mod;
	int total_count = 0;
	for (int l = 1; l <= n; l++) // for substring of all lengths.
	{
		set<ll> forl;
		for (int i = 0; i <= n - l; i++)
		{
			ll cur_hash = (hash[i + l] - hash[i] + mod) % mod;
			cur_hash = cur_hash * pow_p[n - i - 1] % mod;
			forl.insert(cur_hash);
		}
		total_count += forl.size();
	}
	cout << total_count ;
}
int main()
{
	IO();

	solve();

	return 0;
}


