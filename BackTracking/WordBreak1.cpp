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
    // recursion
    // return Util(m,q,0);
    
    
    // dp
    
    int n = q.size();
    bool dp[n];
    for(int i=0;i<n;i++) dp[i] = false;
    
    vector<int> index;
    index.push_back(-1);
    
    for(int i=0;i<n;i++)
    {
        int f = 0;
        int size = index.size();
        for(int j = size-1;j>=0;j--)
        {
            string now = q.substr(index[j]+1,i-index[j]);
            if(m[now])
            {
                f=1;
                break;
            }
        }
        if(f)
        {
            dp[i] = true;
            index.push_back(i);
        }
    }
     return dp[n-1];
}
int main() {
	//code
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
