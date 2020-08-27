//Given an input string and a dictionary of words, find out if the input string can be segmented into a space-separated sequence of dictionary words.
//See following examples for more details.

// Consider the following dictionary
// { i, like, sam, sung, samsung, mobile, ice,
//   cream, icecream, man, go, mango}

// Input:  ilike
// Output: Yes
// The string can be segmented as "i like".

// Input:  ilikesamsung
// Output: Yes
// The string can be segmented as "i like samsung" or "i like sam sung".


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
