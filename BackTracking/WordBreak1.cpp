#include <bits/stdc++.h>
using namespace std;
bool Util(map<string,bool> &m,string&q,int i)
{
    int n= q.size();
    if(n<=i) return true;
    for(int j=i;j<n;j++)
    {
        if(m[q.substr(i,j-i+1)])
        {
            if(Util(m,q,j+1)) return true;
        }
    }
    return false;
}
bool solve(map<string,bool> &m,string &q)
{
    return Util(m,q,0);
}
int main() {

	int t;cin>>t;while(t--)
	{
	    map<string,bool> m;
	    int n;cin>>n;
	    while(n--) {
	        string a;cin>>a;
	        m[a] = true;
	    }
	    string que;cin>>que;
	    cout<<solve(m,que)<<endl;
	}
	return 0;
}
