//Given a list of n strings , each no longer than m characters, find all the duplicate strings and divide them into groups

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll compute_hash(string s)
{
	int p = 31, m = 1e9 + 9;
	ll hash_value = 0 , p_pow = 1;
	for (char c : s)
	{
		hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
		p_pow = (p_pow * p) % m;
	}
	return hash_value;
}

vector<vector<int>> group_identical_strings_by_indcies(string a[], int n)
{
	pair<ll, int>  hash_values[n];
	for (int i = 0; i < n; i++)
		hash_values[i] = {compute_hash(a[i]), i};
	vector<vector<int>> groups;
	sort(hash_values, hash_values + n);
	for (int i = 0; i < n; i++)
	{
		if (i == 0 || hash_values[i - 1].first != hash_values[i].first) groups.emplace_back();
		groups.back().push_back(hash_values[i].second);
	}
	return groups;
}

void solve()
{
	int n; cin >> n;
	string a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<vector<int>> g =  group_identical_strings_by_indcies(a, n);
	for (auto j : g)  // groups
	{
		for (auto i : j)  indics in each groups
			cout << i << " ";
		cout << endl;
	}

}

int main()
{


	solve();
	return 0;
}


