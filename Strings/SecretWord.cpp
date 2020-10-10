// UVA 12467 - KMP

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define all(v) v.begin(),v.end()
#define len(s) int(s.size())

int n;
void solve()
{

	string s; cin >> s;
	n = len(s);
	int pre[n + n + 1];
	pre[0] = 0;
	string b = s;
	reverse(all(b));
	s = s + '^' +  b;
	for (int i = 1; i < len(s); i++)
	{
		int j = pre[i - 1];
		while (j && s[i] != s[j]) j = pre[j - 1];
		pre[i] = j + (s[i] == s[j]);
	}
	int ans = 1;
	for (int i = n + 1 ; i < len(s); i++)
		ans = max(ans, pre[i]);
	string g = s.substr(0, ans);
	reverse(all(g));
	cout << g << endl;

}
int  main()
{
	int t; cin >> t; while (t--) {
		solve();
	}

}

