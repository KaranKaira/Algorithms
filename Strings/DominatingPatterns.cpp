// UVA 1449 - Dominating Patterns
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define len(s) int(s.size())
#define pb push_back
#define eb emplace_back


void solve()
{
	while (1) {
		cin >> n;
		if (n == 0) return;
		string p[n];
		map<string , int> freq;
		for (int i = 0; i < n; i++) cin >> p[i];
		string t; cin >> t;
		for (int i = 0; i < n; i++)
		{
			string pa = p[i];
			string combo = pa + '^' + t;
			int lps[len(combo)];
			lps[0] = 0;
			for (int i = 1; i < len(combo); i++)
			{
				int j = lps[i - 1];
				while (j && combo[i] != combo[j] ) j = lps[j - 1];
				lps[i] = j + (combo[i] == combo[j]);
			}

			for (int i = len(pa) + 1; i < len(combo); i++)
				if (lps[i] == len(pa)) freq[pa]++;
		}
		int ans = 0;
		vector<string> r;
		for (int i = 0; i < n; i++)
		{
			if (freq[p[i]] > ans)
			{
				r = vector<string>();
				r.eb(p[i]);
				ans = freq[p[i]];
			}
			else if (freq[p[i]] == ans) r.eb(p[i]);
		}

		cout << ans << endl;
		for (auto c : r) cout << c << endl;
	}
}
int  main()
{

	solve();

}

