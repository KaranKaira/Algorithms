#include <bits/stdc++.h>
using namespace std;

void  solve()
{
	string a, b;
	while (cin >> a >> b)
	{
		int n = a.size();
		int m = b.size();
		int dp[n + 1][m + 1];
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (a[i - 1] == b[j - 1])
					dp[i][j] = 1 + dp[i - 1][j - 1];
				else dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);

		string sub = "";
		int i = n, j = m;
		while (i > 0 && j > 0)
		{
			if (a[i - 1] == b[j - 1])
			{
				sub = a[i - 1] + sub;
				i--; j--;
			}
			else {
				if (dp[i - 1][j] > dp[i][j - 1])
					i--;
				else j--;
			}
		}

		int k = 0;
		int s = sub.size();

		i = 0, j = 0;
		while (k < s )
		{
			while (i < n && a[i] != sub[k])
			{
				cout << a[i++];
			}
			while (j < m && b[j] != sub[k])
			{
				cout << b[j++];
			}
			cout << sub[k++];

			i++; j++;
		}
		while (i < n) cout << a[i++];
		while (j < m) cout << b[j++];
		cout << endl;
	}
}

int main()
{
	solve();
}


