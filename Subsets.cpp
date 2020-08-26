#include <bits/stdc++.h>
using namespace std;
set<vector<int>> ans;
void subsets(int a[],int n,int k,vector<int> subset)
{
    if(k == n)
    {
        if(0 == int(subset.size())) ans.insert(vector<int>(0));
       else  {
           sort(subset.begin(),subset.end());
           ans.insert(subset);
       }
    }
    else {
        subsets(a,n,k+1,subset);
        subset.push_back(a[k]);
        subsets(a,n,k+1,subset);
    }
}
int main() {
	int t;cin>>t;while(t--)
	{
	    int n;cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++) cin>>a[i];
        ans.clear();
        vector<int> subset;
        subsets(a,n,0,subset);
    
        for(auto it = ans.begin();it!=ans.end();it++)
        {
            vector<int> th = *it;
            cout<<"(";
            int size = th.size();
            for(int i=0;i<size-1;i++) cout<<th[i]<<" ";
            if(size-1>=0) cout<<th[size-1];
            cout<<")";
        }
        cout<<endl;
	}
	return 0;
}
