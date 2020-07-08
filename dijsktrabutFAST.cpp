#include <bits/stdc++.h>
using namespace std;
# define fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define all(v) v.begin(),v.end()
typedef long long ll;



ll d[100010] ;
vector<int> adj[100001];
map<pair<ll,ll>,ll> m;
priority_queue<ll> q;
int n,ma;
int pr[100001] ;

// code start here

// dijstra with proitiy queue with O(VlogV)

void printpath(int n)
{
	if(n!=1) printpath(pr[n]);
	cout<<n << " ";
}
void solve()                                                                                     
{ 	
	cin>>n>>ma;
	for(int i=0;i<ma;i++)
		{
			int a,b,c;cin>>a>>b>>c;
			adj[a].push_back(b);
			adj[b].push_back(a);
			m[{a,b}] = m[{b,a}] = c;
		}
	d[1] = 0;
	for(int i=2;i<=n;i++)
		d[i] = 1e18;
	q.push(1);

	while(!q.empty())
	{
		int k = q.top();
		q.pop();
		for(int i = 0;i<adj[k].size();i++)
			{
				int z = adj[k][i];
				if(d[z] > d[k] + m[{k,z}])
					{
						pr[z] = k;
						q.push(z);
						d[z] = d[k] + m[{k,z}];
					}

				}


		}
	if(d[n]==1e18) {
		cout<<-1;return ;
	}
		printpath(n);

}
int main()
{
	solve();
	return 0;
}


 
