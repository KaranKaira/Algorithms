#include <bits/stdc++.h>
using namespace std;
#define ha "YES"
#define na "NO"


int leader(int a, int p[])
{
	return p[a] = (p[a] == a ? a : leader(p[a], p));
}
void Unite(int a, int b, int p[], int s[])
{
	a = leader(a, p) ;
	b = leader(b, p);
	if (s[a] > s[b])
		swap(a, b);
	p[a] = b;
	s[b] += s[a];
}


void  solve()
{
	int n, m; cin >> n >> m;
	int p[n + 1], s[n + 1];
	for (int i = 1; i <= n; i++)
	{
		p[i] = i ;
		s[i] = 1;
	}
	for (int i = 0 ; i < m; i++)
	{
		string op; cin >> op;
		int x, y; cin >> x >> y;

		if (op == "union")
		{
			Unite(x, y, p, s);
		}
		else {
			if (leader(x, p) == leader(y, p))
				cout << ha << endl;
			else cout << na << endl;
		}

	}
}
int  main()
{
	
	solve();


	return 0;
}

