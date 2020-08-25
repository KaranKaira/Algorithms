//Given a set of N jobs where each job i has a deadline and profit associated to it. 
//Each job takes 1 unit of time to complete and only one job can be scheduled at a time.
//We earn the profit if and only if the job is completed by its deadline. The task is to find the maximum profit and the number of jobs done.

#include <bits/stdc++.h>
using namespace std;
struct job{
    int end,profit,id;
};
bool comp(job a,job b)
{
   return (a.profit > b.profit);
   
   
}
int main() {
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    job a[n];
	    for(int i=0;i<n;i++) cin>>a[i].id>>a[i].end>>a[i].profit;
	    sort(a,a+n,comp);
        unordered_map<int,bool> m;
	    int ans =0;
	    int num = 0;
	    for(int i=0;i<n;i++)
	    {
	        for(int j = a[i].end-1;j>=0;j--)
	        {
	            if(m.find(j)==m.end())
	            {
	                m[j] = true;
	                ans+=a[i].profit;
	                num++;
	                break;
	            }
	        }
	    }
	    
	    cout<<num<<" " << ans<<endl;
	  
	    
	}
	return 0;
}
