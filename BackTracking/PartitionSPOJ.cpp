//A partition of positive integer m into n components is any sequence a1,...,an of positive integers such that a1+...+an=m and a1<=a2<=...<=an. 
//Your task is to determine the partition, which occupies the k-th position in the lexicographic order of all partitions of m into n components.

//The lexicographic order is defined as follows: sequence a1,...,an comes before b1,...,bn iff there exists such an integer i,1<=i<=n, that aj=bj for all j, 1<= j< i, and ai< bi.

#include <bits/stdc++.h>
using namespaces std;
int no = 0;
int add(vector<int> & ans)
{
	int s = 0;
	for (int i : ans) s += i;

	return s;
}
bool cal(int m, int n, int k, vector<int> &ans)
{
	if (int(ans.size()) == n)
	{
		if (add(ans) == m)
		{
			no++;
			if (no == k) return true;
			else return false;
		}
		return false;
	}

	for (int i = 1; i < 10; i++)
	{
		ans.push_back(i);
		if (cal(m, n, k, ans)) return true;
		ans.pop_back();
	}

	return false;

}
void  solve()
{

	int m, n, k; cin >> m >> n >> k;
	vector<int> ans;

	cal(m, n, k, ans);

	for (int i : ans)
		cout << i << " ";

}


int main()
{
	int t; cin >> t; while (t--)
		solve();
}
