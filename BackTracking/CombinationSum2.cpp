#include <bits/stdc++.h>
using namespace std;
void Util(int a[],int n,int cur_sum ,set<vector<int>>&res,vector<int> now,int i)
{
     if(cur_sum==0) {
        res.insert(now);
    }
    if(cur_sum<0 || i == n) return;
   
    Util(a,n,cur_sum,res,now,i+1);
    now.push_back(a[i]);
    Util(a,n,cur_sum-a[i],res,now,i+1);
}
set<vector<int>> Combinations(int a[],int target,int n)
{
    vector<int> now;
    set<vector<int>> res;
    Util(a,n,target,res,now,0);
    return res;
}
int main() {
	int t;cin>>t;while(t--)
	{
	    int n;cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++ ) cin>>a[i];
	    sort(a,a+n);
	    int b;cin>>b;
	    set<vector<int>> ans  = Combinations(a,b,n);
	    if(ans.size()==0)
	    {
	        cout<<"Empty"<<endl;
	        continue;
	    }
	    for(auto it = ans.begin();it!=ans.end();it++)
	    {
	        vector<int> h = *it;
	        if(h.size()==0) continue;
	        
	        cout<<"(";
	        for(int j=0;j<int(h.size())-1;j++)
	        cout<<h[j]<<" ";
	        cout<<h[int(h.size())-1]<<")";
	    }
	    cout<<endl;
	    
	}
	return 0;
}
