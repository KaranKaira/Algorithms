#include <bits/stdc++.h>
using namespace std;
void Util(vector<int> a,int cur_sum,vector<vector<int>>&res,vector<int> now,int i)
{
    if(cur_sum<0) return ;
    if(cur_sum == 0)
    {
        res.push_back(now);
        return ;
    }
    
    while(i<a.size() && cur_sum - a[i] >= 0)
    {
        now.push_back(a[i]);
        Util(a,cur_sum-a[i],res,now,i);
        i++;
        now.pop_back();
    }
}
vector<vector<int>> combination(vector<int> a,int target)
{
    vector<int> now;
    vector<vector<int>> res;
    Util(a,target,res,now,0);
    return res;
}
int main() {
    
    int t;cin>>t;while(t--)
    {
        int n;cin>>n;
        vector<int> a;
        for(int i=0;i<n;i++) {int h;cin>>h;a.push_back(h);}
        int b;cin>>b;
        sort(a.begin(),a.end());
        a.erase(unique(a.begin(), a.end()), a.end()); 
        vector<vector<int>> ans = combination(a,b);
        for(auto it=ans.begin();it!=ans.end();it++)
        {
            vector<int> now = *it;
            cout<<"(";
            for(int i=0;i<int(now.size())-1;i++)
            cout<<now[i]<<" ";
            if(int(now.size()));
            cout<<now[int(now.size())-1]<<")";
        }
        if(ans.size()==0) cout<<"Empty";
     cout<<endl;   
    }
	return 0;
}
