// You are given a string s consisting of lowercase Latin letters. Character c is called k-dominant iff each substring of s with length at least k contains this character c.

 // You have to find minimum k such that there exists at least one k-dominant character.
// Input
// The first line contains string s consisting of lowercase Latin letters (1 ≤ |s| ≤ 100000).

 // Output
 // Print one number — the minimum value of k such that there exists at least one k-dominant character.

#include <bits/stdc++.h>
using namespace std;
bool isvalid(string &s, int n, int k)
{
	for (char c = 'a' ; c <= 'z'; c++)
	{
		int cnt = 0;
		for (int i = 0; i < k; i++)
			cnt += s[i] == c;
		if (cnt == 0) continue;
		for (int i = k; i < n; i++)
		{
			cnt += s[i] == c;
			cnt -=  s[i - k] == c;
			if (cnt == 0) break;
		}
		if (cnt == 0) continue;
		return true;
	}

	return 0;

}

void solve()
{
	string s; cin >> s;
	int n = s.size();
	int l = 1, r = n;
	int ans ;
	while (l <= r)
	{
		int mid = l + (r - l) / 2;

		if (isvalid(s, n, mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans << endl;
}


int main()
{

	solve();
}
