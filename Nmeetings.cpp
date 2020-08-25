#include <bits/stdc++.h>
using namespace std;
struct job{
    int st, end,ind;
};   
bool comp(job a,job b)
{
    return a.end < b.end;
}
int main() {
    int t;cin>>t;while(t--)
    {
        int n;cin>>n;
        job a[n];
        for(int i=0;i<n;i++) cin>>a[i].st;
        for(int i=0;i<n;i++) {cin>>a[i].end;a[i].ind = i+1;}
        sort(a,a+n,comp);
        int k=0;
        cout<<a[k].ind<<" ";
        
        for(int i=1;i<n;i++)
        {
            if(a[i].st  >= a[k].end) {
                cout<<a[i].ind<<" ";
                k = i;
            }
            
        }
        cout<<endl;
    }
	return 0;
}
